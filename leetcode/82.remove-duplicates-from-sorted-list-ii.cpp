/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (35.68%)
 * Likes:    1386
 * Dislikes: 100
 * Total Accepted:    232.8K
 * Total Submissions: 651.6K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 * Return the linked list sorted as well.
 *
 * Example 1:
 *
 *
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 *
 *
 * Example 2:
 *
 *
 * Input: 1->1->1->2->3
 * Output: 2->3
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
    ListNode* header = new ListNode;
    header->next = head;
    ListNode* o = header;
    ListNode* p;
    ListNode* q;
    while ((p = o->next) && (q = p->next)) {
      if (p->val != q->val) {
        o = o->next;
      } else {
        while ((q = p->next) && (p->val == q->val)) {
          //   delete p;
          p = q;
        }
        // delete p;
        o->next = q;
      }
    }
    return header->next;
  }
};
// @lc code=end
