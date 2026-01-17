import os
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("command")
parser.add_argument("-p", "--problem", dest="problem")
args = parser.parse_args()


def template():
    problem = args.problem
    # create folder
    try:
        os.mkdir(problem)
    except FileExistsError:
        pass

    # create template file
    f_md = f"""# Problem: {problem}
Link: https://leetcode.com/problems/{problem}

# Tags

# Similar

# Solution
"""
    f_cpp = """#include <bits/stdc++.h>
using namespace std;
"""

    with open(f"{problem}/problem_.md", "w", encoding="utf-8") as f:
        f.write(f_md)
    with open(f"{problem}/s1.cpp", "w", encoding="utf-8") as f:
        f.write(f_cpp)
    with open(f"{problem}/s1.py", "w", encoding="utf-8") as f:
        f.write("")


match args.command:
    case "template":
        template()
