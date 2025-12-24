# Problem: 3752_lexicographically-smallest-negated-permutation-that-sums-to-target

https://leetcode.com/problems/lexicographically-smallest-negated-permutation-that-sums-to-target

# Tags

#medium #greedy

# Solution

1. Let sum=(1+n)*n/2, then rem=(sum-target)/2 is the abs of sum of the negative numbers we need to flip.
2. Loop the negative numbers start from n (greedy) to 1 to find out all negative numbers.
3. Generate the vector with neg and pos numbers.
