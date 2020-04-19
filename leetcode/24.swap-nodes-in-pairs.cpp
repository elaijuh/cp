/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (48.86%)
 * Likes:    1919
 * Dislikes: 159
 * Total Accepted:    434.1K
 * Total Submissions: 886.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example:
 *
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* header = new ListNode;
    header->next = head;
    ListNode* p = header;
    while (p->next && p->next->next) {
      ListNode* l = p->next;
      ListNode* r = p->next->next;
      l->next = r->next;
      r->next = l;
      p->next = r;
      p = p->next->next;
    }
    return header->next;
  }
};
// @lc code=end
