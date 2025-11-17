# Problem

https://leetcode.com/problems/count-distinct-integers-after-removing-zeros

# Tags

#medium #math

# Solution

Given n has d digits

- Step 1. calculate for numbers without '0' up to d-1 digits.
- Step 2. calculate for numbers without '0' having d digits up to n.
- Step 3. sum 1 and 2

## Step 1:

Let S(k) be the count of non-0-containing numbers up to a k digit number. Then `S(k) = pow(9,d-1)`. `S(1)+S(2)+...S(d-1)=(pow(9,d)-1)/(9-1)` according to geometric sequence nature.

## Step 2:

Loop n digit by digit. The ith (from left to right) digit n[i] can generate `(n[i]-1)*pow(9,d-i-1)` non-0-containing numbers. Break when counting to '0' in n.

## Reference

Similar problem to count 0 containing numbers from GeeksForGeeks

https://www.geeksforgeeks.org/dsa/count-numbers-having-0-as-a-digit/
