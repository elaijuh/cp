import json
from pathlib import Path
from typing import Annotated

import typer

from cp.tools import AtcoderFetcher
from cp.tools import AtcoderGenerator
from cp.tools.utils import get_template_path

app = typer.Typer()


@app.command("fetch")
def fetch(
    problem_slug: str | None = typer.Option(
        None, "-s", "--problem-slug", help="Problem slug (e.g., 'abc445_a')"
    ),
) -> None:
    fetcher = AtcoderFetcher()

    try:
        data = fetcher.get_problem_by_slug(problem_slug)
        typer.echo(json.dumps(data, indent=2))
    except Exception as e:
        typer.echo(f"Error fetching problem: {e}", err=True)
        raise typer.Exit(1) from None


@app.command("generate")
def generate(
    problem_slugs: Annotated[
        list[str] | None,
        typer.Option(
            "-s", "--problem-slug", help="Problem slug(s) (use multiple -s flags)"
        ),
    ] = None,
    output: Annotated[
        str, typer.Option(".", "-o", "--output", help="Output directory")
    ] = "atcoder",
    force: Annotated[
        bool, typer.Option("--force", help="Force overwrite existing files")
    ] = False,
):
    problem_slugs = problem_slugs if problem_slugs is not None else []
    template_dir = get_template_path("atcoder")
    output_dir = Path(output)

    fetcher = AtcoderFetcher()
    problems = []
    if problem_slugs:
        try:
            for p in problem_slugs:
                problems.append(fetcher.get_problem_by_slug(p)[-1])
        except Exception as e:
            typer.echo(f"Error fetching problem: {e}", err=True)
            raise typer.Exit(1) from None

    # Generate each problem
    success_count = 0
    failed_count = 0
    created_dirs: list[Path] = []

    generator = AtcoderGenerator()
    for p in problems:
        try:
            problem_id = p.get("id")
            contest_id = p.get("contest_id")
            problem_index = p.get("problem_index")
            generator.generate_problem(p, template_dir, output_dir, force)
            created_dirs.append(output_dir / contest_id / problem_index)
            success_count += 1
        except typer.Exit:
            # typer.Exit was already handled with proper error message
            failed_count += 1
        except Exception as e:
            typer.echo(f"Error generating problem '{problem_id}': {e}", err=True)
            failed_count += 1

    typer.echo(f"Completed: {success_count} successful, {failed_count} failed")

    if failed_count > 0:
        raise typer.Exit(1)
