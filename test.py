import subprocess
import json
import os
import sys

# 设置 PYTHONIOENCODING 环境变量为 utf-8
os.environ['PYTHONIOENCODING'] = 'utf-8'

def run_test(test_dir):
    input_path = os.path.join(test_dir, "input.txt")
    output_path = os.path.join(test_dir, "output.txt")
    error_path = os.path.join(test_dir, "error.txt")
    user_json_path = os.path.join(test_dir, "users.json")
    expected_output_path = os.path.join(test_dir, "expected_output.json")
    output_json_path = os.path.join(test_dir, "output.json")
    expected_output_txt_path = os.path.join(test_dir, "expected_output.txt")

    # 读取输入文件
    with open(input_path, "r", encoding="utf-8") as input_file:
        input_data = input_file.read()

    # 确定输出目录
    test_output_dir = os.path.join(
        os.path.dirname(os.path.abspath(__file__)),
        "testout",
        os.path.basename(test_dir),
    )
    os.makedirs(test_output_dir, exist_ok=True)

    actual_output_path = os.path.join(test_output_dir, "output.txt")
    actual_error_path = os.path.join(test_output_dir, "error.txt")
    # 输出路径output与error.txt
    print(f"Output path: {actual_output_path}")
    print(f"Error path: {actual_error_path}")

    # 使用 subprocess 重定向 stdout 和 stderr
    executable_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'out', 'MyProject.exe')
    print(f"Executable path: {executable_path}")

    # 在输入数据后面添加一行 'quit'
    
    input_data += "\nquit\n"

    if not os.path.isfile(executable_path):
        print(f"Executable not found: {executable_path}")
        return False

    with open(actual_output_path, "w", encoding="utf-8") as output_file, open(
        actual_error_path, "w", encoding="utf-8"
    ) as error_file:
        process = subprocess.Popen(
            [executable_path, user_json_path],#user_json_path,启动程序时的参数
            stdin=subprocess.PIPE,
            stdout=output_file,
            stderr=error_file,
            text=True,
        )
        process.communicate(input=input_data)

    # # 比较实际输出和预期输出
    # with open(actual_output_path, "r", encoding="utf-8") as output_file:
    #     actual_output = output_file.read()

    # with open(expected_output_txt_path, "r", encoding="utf-8") as expected_output_file:
    #     expected_output = expected_output_file.read()

    # if actual_output.strip() != expected_output.strip():
    #     print(f"Test in {test_dir} Failed.")
    #     return False

    # 比较 JSON 文件
    # with open(os.path.join(test_output_dir, "user.inputjson"), "r", encoding="utf-8") as actual_json_file:
    with open(output_json_path, "r", encoding="utf-8") as actual_json_file:
        actual_json = json.load(actual_json_file)

    with open(expected_output_path, "r", encoding="utf-8") as expected_json_file:
        expected_json = json.load(expected_json_file)

    if actual_json != expected_json:
        print(f"JSON Output in {test_dir} does not match expected output.")
        print(f"Expected: {expected_json}")
        return False

    print(f"Test in {test_dir} Passed.")
    return True

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: test.py <test_directory>")
        sys.exit(1)

    test_dir = sys.argv[1]
    if run_test(test_dir):
        print("Test Passed")
        sys.exit(0)
    else:
        print("Test Failed")
        sys.exit(1)
