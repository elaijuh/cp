from pathlib import Path


def get_template_path() -> Path:
    current_file = Path(__file__)
    resources_path = current_file.parent.parent / "cli" / "templates" / "leetcode"

    if resources_path.exists():
        return resources_path

    raise FileNotFoundError(f"Template resources not found at {resources_path}.")
