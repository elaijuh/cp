from pathlib import Path
from collections import defaultdict

import typer
from cookiecutter.main import cookiecutter

from .parser import HTMLParser


class LeetcodeGenerator:
    def __init__(self):
        pass

    def prepare_json_data(self, problem: dict) -> dict:
        data = defaultdict()
        data["problem_name"] = problem["slug"].replace("-", "_")
        data["problem_number"] = problem["number"]
        data["problem_slug"] = problem["slug"]
        data["problem_title"] = problem["title"]
        data["difficulty"] = problem["difficulty"].lower()
        data["topics"] = ",".join(
            map(lambda x: f"[#{x}](https://leetcode.com/tag/{x})", problem["topics"])
        )
        data["readme_description"] = problem["description"]
        data["readme_examples"] = {
            "list": [
                {
                    "number": e["number"],
                    "image": e["image"],
                    "text": f"<pre>{e['text']}</pre>",
                }
                for e in problem["examples"]
            ]
        }
        data["readme_constraints"] = "\n".join(
            map(lambda x: f"- {x}", problem["constraints"])
        )

        data["solution_class_name"] = ""
        parsed_solution = HTMLParser.parse_solution(problem["python_code"])
        data["solution_imports"] = "\n".join(
            [f"from cp.dsa.leetcode import {c}" for c in parsed_solution["imports"]]
        )
        data["solution_contents"] = parsed_solution["solution"]

        return data

    def check_problem_exists(
        self, problem_name: str, output_dir: Path, force: bool
    ) -> None:
        if not force:
            problem_dir = output_dir / problem_name
            if problem_dir.exists():
                typer.echo(
                    f"Error: Problem '{problem_name}' already exists. Use --force to overwrite.",
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
            problem_name = data.get("problem_name", "unknown")
            typer.echo(f"Generated problem: {problem_name}")
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
        problem_name = data.get("problem_name", "unknown")
        self.check_problem_exists(problem_name, output_dir, force)
        self.generate_from_template(data, template_dir, output_dir)
