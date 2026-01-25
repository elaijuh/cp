import os
import argparse
import json
import codeforces_api

parser = argparse.ArgumentParser()
parser.add_argument("command")
parser.add_argument("-c", "--contest", dest="contest")
parser.add_argument("-p", "--problem", dest="problem")
args = parser.parse_args()

with open("api_key.json", "r", encoding="utf-8") as f:
    api_key = json.load(f)

cf_api = codeforces_api.CodeforcesApi(api_key["key"], api_key["secret"])


def get_user(user):
    users = cf_api.user_info(handles=[user])

    for u in users:
        print(
            f"handle: {u.handle}, rank: {u.rank}, max rank: {u.max_rank}, rating: {u.rating}, max rating: {u.max_rating}"
        )


def template():
    contest_id, problem_id = args.contest, args.problem
    res = cf_api.contest_standings(contest_id, start=1, count=5)
    contest, problems = res["contest"], res["problems"]

    # create folder
    try:
        os.mkdir(contest_id)
    except FileExistsError:
        pass

    # create template file
    problem = next((p for p in problems if p.index.lower() == problem_id), None)
    problem_tags = " ".join(["#" + t for t in problem.tags])
    f_md = f"""\
# Problem
Contest: {contest.name}\\
Problem: {problem.index}.{problem.name}\\
Link: https://codeforces.com/contest/{contest_id}/problem/{problem_id}\\
Points: {problem.points}
Rating: {problem.rating}

# Tags
{problem_tags}

# Solution
"""
    with open(f"{contest_id}/{problem_id}.md", "w", encoding="utf-8") as f:
        f.write(f_md)
    with open(f"{contest_id}/{problem_id}.py", "w", encoding="utf-8") as f:
        f.write("")


match args.command:
    case "template":
        template()
