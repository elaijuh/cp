from pathlib import Path


def get_template_path(platform: str) -> Path:
    current_file = Path(__file__)
    resources_path = current_file.parent.parent / "cli" / "templates" / f"{platform}"

    if resources_path.exists():
        return resources_path

    raise FileNotFoundError(f"Template resources not found at {resources_path}.")
