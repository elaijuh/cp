/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (56.88%)
 * Likes:    1890
 * Dislikes: 118
 * Total Accepted:    253.5K
 * Total Submissions: 445.6K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Note:
 *
 *
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    priority_queue<pair<int, int>> pq;
    vector<int> ans;

    for (int x : nums) {
      m[x]++;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
      pq.push({it->second, it->first});
    }
    while (k--) {
      ans.push_back(pq.top().second);
      pq.pop();
    }

    return ans;
  }
};
// @lc code=end
