/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 *
 * https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
 *
 * algorithms
 * Medium (57.35%)
 * Likes:    145
 * Dislikes: 5
 * Total Accepted:    6.6K
 * Total Submissions: 11K
 * Testcase Example:  '7\n' +
  '[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]\n' +
  '[false,false,true,false,true,true,false]'
 *
 * Given an undirected tree consisting of n vertices numbered from 0 to n-1,
 * which has some apples in their vertices. You spend 1 second to walk over one
 * edge of the tree. Return the minimum time in seconds you have to spend in
 * order to collect all apples in the tree starting at vertex 0 and coming back
 * to this vertex.
 *
 * The edges of the undirected tree are given in the array edges, where
 * edges[i] = [fromi, toi] means that exists an edge connecting the vertices
 * fromi and toi. Additionally, there is a boolean array hasApple, where
 * hasApple[i] = true means that vertex i has an apple, otherwise, it does not
 * have any apple.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple =
 * [false,false,true,false,true,true,false]
 * Output: 8
 * Explanation: The figure above represents the given tree where red vertices
 * have an apple. One optimal path to collect all apples is shown by the green
 * arrows.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple =
 * [false,false,true,false,false,true,false]
 * Output: 6
 * Explanation: The figure above represents the given tree where red vertices
 * have an apple. One optimal path to collect all apples is shown by the green
 * arrows.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple =
 * [false,false,false,false,false,false,false]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^5
 * edges.length == n-1
 * edges[i].length == 2
 * 0 <= fromi, toi <= n-1
 * fromi < toi
 * hasApple.length == n
 *
 */

// @lc code=start

// 路径上又一个苹果，那么路径上所有的节点都可以放苹果。
class Solution1 {
 public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<int> parents(n, 0);
    for (auto& e : edges) parents[e[1]] = e[0];
    for (int i = n - 1; i >= 0; i--)
      if (hasApple[i]) hasApple[parents[i]] = true;
    int cnt = count(hasApple.begin(), hasApple.end(), true);
    return cnt == 0 ? 0 : (cnt - 1) * 2;
  }
};

// dfs
class Solution {
 public:
  vector<vector<int>> G;
  int dfs(int p, int cost, vector<bool>& hasApple) {
    int childrenCost = 0;
    for (auto x : G[p]) childrenCost += dfs(x, 2, hasApple);
    if (childrenCost == 0 && !hasApple[p]) return 0;
    return cost + childrenCost;
  }
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    G.resize(n);
    for (auto& e : edges) G[e[0]].push_back(e[1]);
    return dfs(0, 0, hasApple);
  }
};
// @lc code=end
