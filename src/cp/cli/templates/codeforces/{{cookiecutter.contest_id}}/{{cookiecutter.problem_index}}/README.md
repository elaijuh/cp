# {{cookiecutter.problem_title}}

{%- if cookiecutter.problem_id %}
**Problem:** [{{cookiecutter.problem_id}}](https://codeforces.com/contest/{{cookiecutter.contest_id}}/problem/{{cookiecutter.problem_index}}/)
{%- endif %}
{%- if cookiecutter.contest_id %}
**Contest:** [{{cookiecutter.contest_name}}](https://codeforces.com/contest/{{cookiecutter.contest_id}})
{%- endif %}

**Tags:** {{cookiecutter.problem_tags}}

**Rating:** {{cookiecutter.problem_rating}}
**Points:** {{cookiecutter.problem_points}}
