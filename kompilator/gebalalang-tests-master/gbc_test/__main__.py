import argparse
import os
from test_generator import get_all_dirs, get_all_files_in_dir
from test_runner import TestRunner
from config import CFG
from print_data import TestResultPrinter

cfg = CFG()
if not cfg.recompile_compiler():
    exit(1)

parser = argparse.ArgumentParser()

parser.add_argument("--required", action="store_true")
args = parser.parse_args()

tests_base_dir = get_all_dirs(cfg.tests_dir)

tests: dict[str, list[str]] = {}
for test in tests_base_dir:
    if args.required and not test.startswith("required"):
        continue
    tests[test] = get_all_files_in_dir(os.path.join("../tests", test))

test_runner = TestRunner(cfg)
r = test_runner(tests)
# old = TestResultPrinter.load_data_from_file("aa.dat")
# TestResultPrinter.compare_results(old, r)
TestResultPrinter.print_data(r)
