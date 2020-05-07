/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (56.47%)
 * Likes:    2866
 * Dislikes: 213
 * Total Accepted:    601K
 * Total Submissions: 1M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,2,3]
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 */

// @lc code=start

/*
// method 1: hashmap
class Solution {
public:
  Solution() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
  }

  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int x:nums) {
      m[x]++;
      if (nums.size()/2<m[x]) return x;
    }
    return 0;
  }
};
*/

/*
// method 2: sort
class Solution {
public:
  Solution() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
  }

  int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
  }
};
*/

// method 3: Boyer-Moore Voting Algorithm
class Solution {
 public:
  Solution() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
  }

  int majorityElement(vector<int>& nums) {
    int cnt = 0;
    int c = nums[0];
    for (auto& x : nums) {
      if (x == c)
        cnt++;
      else if (--cnt == 0) {
        c = x;
        cnt = 1;
      }
    }
    return c;
  }
};

// @lc code=end
