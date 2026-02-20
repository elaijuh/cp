from pathlib import Path
from typing import Any

import requests
import typer
from cookiecutter.main import cookiecutter


class CodeForcesFetcher:
    def __init__(self):
        self.base_url = "https://codeforces.com/api"
        self.headers = {
            "Content-Type": "application/json",
            "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:147.0) Gecko/20100101 Firefox/147.0",
        }

    def get_problem_by_slug(self, problem_slug: str) -> list[Any] | None:
        contest_id = problem_slug.split("_")[0]
        problem_index = problem_slug.split("_")[1]

        response = requests.get(
            f"{self.base_url}/contest.list",
            headers=self.headers,
        )
        if response.status_code == 200:
            data = response.json()
            if data["status"] == "OK":
                contest = list(
                    filter(lambda x: str(x["id"]) == contest_id, data["result"])
                )[0]

        response = requests.get(
            f"{self.base_url}/problemset.problems",
            headers=self.headers,
        )

        if response.status_code == 200:
            data = response.json()
            problems = list(
                filter(
                    lambda x: str(x["contestId"]) == contest_id
                    and x["index"].lower() == problem_index,
                    data["result"]["problems"],
                )
            )
            for p in problems:
                p["id"] = f"{contest_id.lower()}_{problem_index.lower()}"
                p["contestName"] = contest["name"]
                p["contestType"] = contest["type"]
            return problems

        return None


class CodeForcesGenerator:
    def __init__(self):
        pass

    def prepare_json_data(self, problem: dict) -> dict:
        data = {}
        data["problem_id"] = problem["id"]
        data["problem_name"] = problem["name"]
        data["problem_title"] = f"{problem['index']}. {problem['name']}"
        data["problem_index"] = problem["index"]
        data["problem_type"] = problem["type"]
        data["problem_tags"] = ",".join(
            map(lambda x: f"#{x.replace(' ', '_')}", problem["tags"])
        )
        data["problem_points"] = problem["points"] if "points" in problem else None
        data["problem_rating"] = problem["rating"] if "rating" in problem else None
        data["contest_name"] = problem["contestName"]
        data["contest_id"] = str(problem["contestId"])
        data["contest_type"] = problem["contestType"]
        return data

    def check_problem_exists(
        self, contest_id: str, problem_index: str, output_dir: Path, force: bool
    ) -> None:
        if not force:
            problem_dir = output_dir / contest_id / problem_index
            if problem_dir.exists():
                typer.echo(
                    f"Error: Problem '{contest_id, problem_index}' already exists. Use --force to overwrite.",
                    err=True,
                )
                raise typer.Exit(1)

    def generate_from_template(
        self, data: dict, template_dir: Path, output_dir: Path
    ) -> None:
        """Generate problem files using cookiecutter template."""
        try:
            cookiecutter(
                str(template_dir),
                extra_context=data,
                no_input=True,
                overwrite_if_exists=True,
                output_dir=str(output_dir),
            )
            problem_id = data.get("problem_id", "unknown")
            typer.echo(f"Generated problem: {problem_id}")
        except Exception as e:
            typer.echo(f"Error generating template: {e}", err=True)
            raise typer.Exit(1) from None

    def generate_problem(
        self,
        problem: dict,
        template_dir: Path,
        output_dir: Path,
        force: bool = False,
    ) -> None:
        data = self.prepare_json_data(problem)
        contest_id = data.get("contest_id", "unknown")
        problem_index = data.get("problem_index", "unknown")
        self.check_problem_exists(contest_id, problem_index, output_dir, force)
        self.generate_from_template(data, template_dir, output_dir)
