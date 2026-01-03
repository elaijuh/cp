# number-of-ways-to-paint-n-3-grid

https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

# Tags

#hard #math #dp

# Solution

## s1 math

Split combination into 2 categories: 2-color and 3-color.

- Each 2-color combination can generate 2 possibilities of 3-color and 3 possiblities of 2-color. Eg: YRY->RYG,GYR,RYR,GYG,RGR
- Each 3-color combination can generate 2 possibilities of 3-color and 2 possiblities of 2-color. Eg: YRG->GYR,RGY,RYR,RGR
- Based on above assumption, we can calculate final 2-color and 3-color
