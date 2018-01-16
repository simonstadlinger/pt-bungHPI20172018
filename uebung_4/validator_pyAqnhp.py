#!/usr/bin/env python2
# -*- coding: UTF-8 -*-

"""
PT1/WT17/U4/Validator/v2

Danke, dass du dieses Validatorscript heruntergeladen hast.
Wenn es dir lokal noch hilfreicher sein soll, kannst du dir
die Fehler rot einfärben lassen.

Bash-Nutzer führen dazu einfach folgendes aus (alle anderen googeln):

	$ color() (set -o pipefail; "$@" 2>&1>&3 | sed $'s,.*,\e[31m&\e[m,' >&2) 3>&1
	$ color python2 path/to/validator.py

Viel Spaß!
"""

import operator
import os
import subprocess
import sys

#-------------------------------------------------------------------------------

def log(msg="", newLine=True, okay=False):
	f = sys.stdout if okay else sys.stderr
	f.write("%s\n" % msg if newLine else msg)
	f.flush()

def silent_atoi(s):
	try:
		return int(s)
	except ValueError:
		return None

#-------------------------------------------------------------------------------

class Test(object):

	def exec_(self, input_text, *cmd_and_args):
		p = subprocess.Popen(cmd_and_args, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
		return tuple(map(lambda s: s.strip(), p.communicate(input=input_text)[:2])) + (p.returncode, )

	def run_prog(self, *cmd_and_args):
		return self.exec_("", *cmd_and_args)[0]

	def test(self):
		self.run()
		okay = self.okay()
		log(self.what(), okay=okay)
		return okay

	def run(self):
		raise NotImplementedError

	def what(self):
		raise NotImplementedError

	def okay(self):
		raise NotImplementedError

class EmptyTestLine(Test):

	def run(self):
		pass

	def what(self):
		return ""

	def okay(self):
		return True

class TestGroup(Test):
	"""A group of tests, where all tests are executed"""

	def __init__(self, *tests):
		self.tests = tests
		self.all_okay = False

	def test(self):
		self.all_okay = all([t.test() for t in self.tests])
		return self.all_okay

	def okay(self):
		return self.all_okay

class AbortingTestGroup(TestGroup):
	"""A group of tests, where the first failed test stops the entire group"""

	def test(self):
		self.all_okay = all(t.test() for t in self.tests)
		return self.all_okay

class FileMimeTest(Test):
	"""Is the specified file existant of a given mimetype?"""

	def __init__(self, fname, expected_mime_toplevel):
		self.fname = fname
		self.expected_mime_toplevel = expected_mime_toplevel

	def run(self):
		self.exists = os.path.exists(self.fname)
		self.mimetype = self.run_prog("file", "--mime-type", "-b", self.fname)
		self.ttype = self.mimetype.split("/", 1)[0]

	def what(self):
		if not self.exists:
			return '# file "%s" does not exist' % self.fname
		return '# file "%s" exists and is "%s" (expected "%s/*")' % (self.fname, self.mimetype, self.expected_mime_toplevel)

	def okay(self):
		return self.exists and self.ttype == self.expected_mime_toplevel

class ReturnCodeTest(Test):

	def __init__(self, progname, args=None, retcode=0, showstdout=False):
		self.cmdline = [progname] + map(str, args or [])
		self.expected = retcode
		self.exception = None
		self.showstdout = showstdout
		self.stdout = ""

	def _get_output(self, tpl):
		self.stdout = tpl[0]
		return tpl[2]

	def run(self):
		try:
			self.output = self._get_output(self.exec_("", *self.cmdline))
		except Exception as e:
			self.exception = e

	def what(self):
		_s = lambda a: " ".join(map(str, a))
		return "$ %s -- exited with %s (expected %d)%s" % (
					_s(self.cmdline),
					str(self.output) if self.exception is None else str(self.exception),
					self.expected,
				"" if not (self.showstdout and self.stdout) else ("\n%s" % self.stdout))

	def okay(self):
		return self.output == self.expected

class ExecutionTest(ReturnCodeTest):
	"""Run a programm and compare the lines of stdout to a list of expected output."""

	def __init__(self, progName, args, expected, compare=operator.eq, key=lambda x: x):
		super(ExecutionTest, self).__init__(progName, args, expected)
		self.compare = compare
		self.key = key

	def _get_output(self, tpl):
		return tpl[0].split("\n")

	def what(self):
		_s = lambda a: " ".join(map(str, a))
		_r = repr
		return "$ " + _s(self.cmdline) + "\n" + \
				(("received: " + _r(self.output))
						if self.exception is None
						else str(self.exception)) + "\n" + \
			   "expected: " + _r(self.expected)

	def okay(self):
		return self.exception is None and self.compare(self.key(self.output), self.key(self.expected))

#-------------------------------------------------------------------------------

class UTF8_Len_Test(ExecutionTest):

	def extract_len(self, s):
		return silent_atoi(s.partition(" = ")[2])

	def run(self):
		super(UTF8_Len_Test, self).run()
		if self.exception is None:
			self.numbers = list(enumerate(map(self.extract_len, self.output)))
			self.output = zip(
						(n for idx, n in self.numbers if idx % 2 == 0),
						(n for idx, n in self.numbers if idx % 2 == 1),
					)

class WcTestWithInput(Test):

	def __init__(self, input_text, expected):
		self.input_text = input_text
		self.expected = expected
		self.exception = None
		self.output = None

	def run(self):
		try:
			output = self.exec_(self.input_text, "./wc")[0]
			self.output = map(silent_atoi, output.split())
		except Exception as e:
			self.exception = e

	def okay(self):
		return self.expected == self.output

	def what(self):
		return "$ echo -ne %r | ./wc\n%s\nexpected: %s" % (self.input_text,
				"received: " + str(self.output) if self.exception is None else str(self.exception),
				str(self.expected))


#-------------------------------------------------------------------------------

def validate():
	tests = TestGroup(
		AbortingTestGroup(
			ExecutionTest("./cap_rev", ["Guten", "Tag"],       ["GAT",   "NETUG"]),
			ExecutionTest("./cap_rev", ["Wie", "geht", "es?"], ["?SE", "THEG", "EIW"]),
		),
		AbortingTestGroup(
			ExecutionTest("./is_palindrome",  ["rentner", "regallager"], ["YES", "YES"]),
			ExecutionTest("./is_palindrome",  ["kanu",   "kajak"],       ["NO",  "YES"]),
		),
		AbortingTestGroup(
			ExecutionTest("./sundarams_sieve",  [15], map(str, [2, 3, 5, 7, 11, 13])),
			ExecutionTest("./sundarams_sieve",  [30], map(str, [2, 3, 5, 7, 11, 13, 17, 19, 23, 29])),
		),
		AbortingTestGroup(
			WcTestWithInput("Hallo Welt",                    [0, 2, 10]),
			WcTestWithInput("Hallo       Welt",              [0, 2, 16]),
			WcTestWithInput("Lag er im Kajak?\nMir egal.\n", [2, 6, 27]),
		),
		ReturnCodeTest("splint",  ["wc.c"], showstdout=True),
		FileMimeTest("gdb_session.log", "text"),
		UTF8_Len_Test("./strlen_utf8",  ["Viel", "Glück", "🍀",  "2018", "🎉"],
		                                [(4,4),  (6,5),   (4,1), (4,4),  (4,1)]),

	)

	return tests.test()

if __name__ == "__main__":
	sys.exit(0 if validate() else 1)

