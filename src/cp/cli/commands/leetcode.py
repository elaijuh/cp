import json
from pathlib import Path
from typing import Annotated

import typer

from cp.tools.fetcher import LeetcodeFetcher
from cp.tools.generator import LeetcodeGenerator
from cp.tools.utils import get_template_path

ERROR_EXACTLY_ONE_OPTION = (
    "Error: Exactly one of --problem-num or --problem-slug is required"
)

app = typer.Typer()


@app.command("generate")
def generate(
    problem_nums: Annotated[
        list[int] | None,
        typer.Option(
            "-n", "--problem-num", help="Problem number(s) (use multiple -n flags)"
        ),
    ] = None,
    problem_slugs: Annotated[
        list[str] | None,
        typer.Option(
            "-s", "--problem-slug", help="Problem slug(s) (use multiple -s flags)"
        ),
    ] = None,
    output: Annotated[
        str, typer.Option(".", "-o", "--output", help="Output directory")
    ] = "leetcode",
    force: Annotated[
        bool, typer.Option("--force", help="Force overwrite existing files")
    ] = False,
):
    problem_nums = problem_nums if problem_nums is not None else []
    problem_slugs = problem_slugs if problem_slugs is not None else []
    template_dir = get_template_path()
    output_dir = Path(output)

    if sum([len(problem_nums) > 0, len(problem_slugs) > 0]) != 1:
        typer.echo(
            "Error: Exactly one of --problem-num, --problem-slug, "
            "--problem-tag, or --all is required",
            err=True,
        )
        raise typer.Exit(1)

    fetcher = LeetcodeFetcher()
    problems = []
    if problem_nums:
        try:
            for p in problem_nums:
                problems.append(fetch_and_format_problem(fetcher, p, None))
        except Exception as e:
            typer.echo(f"Error fetching problem: {e}", err=True)
            raise typer.Exit(1) from None
    if problem_slugs:
        try:
            for p in problem_slugs:
                problems.append(fetch_and_format_problem(fetcher, None, p))
        except Exception as e:
            typer.echo(f"Error fetching problem: {e}", err=True)
            raise typer.Exit(1) from None

    # Generate each problem
    success_count = 0
    failed_count = 0
    created_dirs: list[Path] = []

    generator = LeetcodeGenerator()
    for p in problems:
        try:
            problem_slug = p.get("slug")
            generator.generate_problem(p, template_dir, output_dir, force)
            created_dirs.append(output_dir / problem_slug)
            success_count += 1
        except typer.Exit:
            # typer.Exit was already handled with proper error message
            failed_count += 1
        except Exception as e:
            typer.echo(f"Error generating problem '{problem_slug}': {e}", err=True)
            failed_count += 1

    typer.echo(f"Completed: {success_count} successful, {failed_count} failed")

    if failed_count > 0:
        raise typer.Exit(1)

    # # Batch format, lint, and type check only the newly created problem directories
    # if created_dirs:
    #     typer.echo("Running format and check...")
    #     batch_format_and_check(created_dirs)


@app.command("fetch")
def fetch(
    problem_num: int | None = typer.Option(
        None, "-n", "--problem-num", help="Problem number (e.g., 1)"
    ),
    problem_slug: str | None = typer.Option(
        None, "-s", "--problem-slug", help="Problem slug (e.g., 'two-sum')"
    ),
) -> None:
    options_provided = sum(x is not None for x in [problem_num, problem_slug])
    if options_provided != 1:
        typer.echo(ERROR_EXACTLY_ONE_OPTION, err=True)
        raise typer.Exit(1)

    fetcher = LeetcodeFetcher()

    try:
        formatted = fetch_and_format_problem(fetcher, problem_num, problem_slug)
        typer.echo(json.dumps(formatted, indent=2))

    except Exception as e:
        typer.echo(f"Error fetching problem: {e}", err=True)
        raise typer.Exit(1) from None


def fetch_and_format_problem(
    fetcher: LeetcodeFetcher, problem_num: int | None, problem_slug: str | None
) -> dict:
    if problem_num is not None:
        problem = fetcher.get_problem_by_number(problem_num)
        if not problem:
            typer.echo(f"Error: Problem number {problem_num} not found", err=True)
            raise typer.Exit(1)
    elif problem_slug is not None:
        problem = fetcher.get_problem_by_slug(problem_slug)
        if not problem:
            typer.echo(f"Error: Problem slug '{problem_slug}' not found", err=True)
            raise typer.Exit(1)
    else:
        typer.echo(ERROR_EXACTLY_ONE_OPTION, err=True)
        raise typer.Exit(1)

    return fetcher.format_problem_info(problem)
