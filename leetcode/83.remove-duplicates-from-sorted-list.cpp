/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (44.58%)
 * Likes:    1268
 * Dislikes: 100
 * Total Accepted:    430.5K
 * Total Submissions: 964.6K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 *
 * Example 1:
 *
 *
 * Input: 1->1->2
 * Output: 1->2
 *
 *
 * Example 2:
 *
 *
 * Input: 1->1->2->3->3
 * Output: 1->2->3
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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;
    ListNode* p = head;
    ListNode* q;
    while (NULL != (q = p->next)) {
      if (p->val != q->val)
        p = q;
      else {
        p->next = q->next;
        delete q;
      }
    }
    return head;
  }
};
// @lc code=end
