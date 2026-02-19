from pathlib import Path
from typing import Any

import requests
import typer
from cookiecutter.main import cookiecutter


class AtcoderFetcher:
    def __init__(self):
        self.base_url = "https://kenkoooo.com/atcoder"
        self.headers = {
            "Content-Type": "application/json",
            "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:147.0) Gecko/20100101 Firefox/147.0",
        }

    def get_problem_by_slug(self, problem_slug: str) -> list[Any] | None:
        response = requests.get(
            f"{self.base_url}/resources/merged-problems.json",
            headers=self.headers,
        )
        if response.status_code == 200:
            data = response.json()
            return list(filter(lambda x: x["id"] == problem_slug, data))
        return None


class AtcoderGenerator:
    def __init__(self):
        pass

    def prepare_json_data(self, problem: dict) -> dict:
        data = {}
        data["problem_name"] = problem["name"]
        data["problem_id"] = problem["id"]
        data["problem_title"] = problem["title"]
        data["problem_index"] = problem["problem_index"]
        data["point"] = problem["point"]
        data["contest_id"] = problem["contest_id"]
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
