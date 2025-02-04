from dataclasses import dataclass
import os
import subprocess


@dataclass(frozen=True)
class CFG:

    # !! CHANGE to where the compiled binary of your compiler is !!
    _gbc_path = "../src/kompilator"

    _main_test_dir = "./tests"
    _vm_path = "./GVM/maszyna-wirtualna"
    _test_dir = "./tests"

    # !! this function runs at the start of all the tests, you can whateever you want here
    # like recompiling your compielr
    # dont remove it, just leave empty with only "pass" in it
    def recompile_compiler(self):
        # cmd = ["cargo", "build", "--manifest-path=../gbc/Cargo.toml"]
        # env = os.environ.copy()
        # env["TERM"] = "xterm-256color"
        # process = subprocess.Popen(
        #     cmd,
        #     stdin=subprocess.PIPE,
        #     stdout=subprocess.PIPE,
        #     stderr=subprocess.PIPE,
        #     text=True,
        #     env=env,
        # )
        # stdout, stderr = process.communicate()

        # rtn = process.wait()

        # if rtn != 0:
        #     print("Recompilation falied")
        #     print(stdout)
        #     print(stderr)
        #     return False
        return True

    # how the tests will run compiler
    # you can do something like ["python", compiler_path, input_file, "-o", output_file]
    def compile_command(self, input_file: str, output_file: str) -> list[str]:
        compiler_path = self.gbc_path
        return [compiler_path, input_file, output_file]

    # you can adjust how to run compiled file
    def run_compiled_command(self, compiled_file: str) -> list[str]:
        return [self.vm_path, compiled_file]

    @property
    def main_test_dir(self) -> str:
        script_dir = os.path.dirname(os.path.abspath(__file__))
        return os.path.join(script_dir, self._main_test_dir)

    @property
    def vm_path(self) -> str:
        script_dir = os.path.dirname(os.path.abspath(__file__))
        return os.path.join(script_dir, self._vm_path)

    @property
    def gbc_path(self) -> str:
        script_dir = os.path.dirname(os.path.abspath(__file__))
        return os.path.join(script_dir, self._gbc_path)

    @property
    def tests_dir(self) -> str:
        script_dir = os.path.dirname(os.path.abspath(__file__))
        return os.path.join(script_dir, self._test_dir)

    def __init__(self):
        file_paths = [self.vm_path, self.gbc_path]
        for file_path in file_paths:
            if not os.path.isfile(file_path):
                print(f"The file {file_path} does not exists.")
                print("fix your config plzz")
                exit(1)
