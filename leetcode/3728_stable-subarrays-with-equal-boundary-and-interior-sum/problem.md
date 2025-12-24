# Problem: 3728_stable-subarrays-with-equal-boundary-and-interior-sum

https://leetcode.com/problems/stable-subarrays-with-equal-boundary-and-interior-sum

# tag

#medium #prefix_sum

# Solution

- Let pre[i] = prefix sum to a[i], then the subarray a[l..r] should meet: pre[r-1]-pre[l]==a[l]==a[r] => pre[r-1]==a[l]+pre[l]
- Use a map to count the number of subarray. unordered_map<ll, unordered_map<ll,ll>> mp
  - `mp[a[i]]` = a map indicates occurence of element a[i] in array
  - `mp[a[i]][pre]` = count of element `a[i]` with prefix sum to `pre`
- Edge case: adjacent two 0 elements should be ingored as min subarray length is 3
