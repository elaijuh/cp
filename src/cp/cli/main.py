import typer
from .commands import leetcode
from .commands import atcoder

app = typer.Typer()


app.add_typer(leetcode.app, name="leetcode")
app.add_typer(atcoder.app, name="atcoder")


@app.callback(invoke_without_command=True)
def main_callback(
    ctx: typer.Context,
):
    if ctx.invoked_subcommand is None:
        typer.echo(ctx.get_help())
        raise typer.Exit()


if __name__ == "__main__":
    app()
