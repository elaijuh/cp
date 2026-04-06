# {{cookiecutter.problem_title}}

{%- if cookiecutter.problem_number %}
**LeetCode:** [Problem {{cookiecutter.problem_number}}](https://leetcode.com/problems/{{cookiecutter.problem_slug}}/description/)
{%- endif %}

**Difficulty:** {{cookiecutter.difficulty}}

**Topics:** {{cookiecutter.topics}}

## Problem Description

{{cookiecutter.readme_description}}

## Examples

{%- for example in cookiecutter.readme_examples.list %}

### Example {{example.number}}:

{%- if example.image %}
{{example.image}}
{%- endif %}
{{example.text}}

{%- endfor %}

## Constraints

{{cookiecutter.readme_constraints}}

{% if cookiecutter.readme_additional %}
{{cookiecutter.readme_additional}}
{% endif %}
