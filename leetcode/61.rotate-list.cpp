/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (29.15%)
 * Likes:    991
 * Dislikes: 966
 * Total Accepted:    251.2K
 * Total Submissions: 860.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, rotate the list to the right by k places, where k is
 * non-negative.
 *
 * Example 1:
 *
 *
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 *
 *
 * Example 2:
 *
 *
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
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
  ListNode* rotateRight(ListNode* head, int k) {
    ListNode* header = new ListNode;
    header->next = head;
    int l = 0;
    ListNode* p = header;
    while (p->next) {
      p = p->next;
      l++;
    }
    if (0 == l) return head;
    ListNode* tail = p;
    int c = k % l;
    if (0 == c) return head;
    l -= c;
    p = header;
    while (0 < l--) {
      p = p->next;
    }
    ListNode* nhead = p->next;
    p->next = NULL;
    tail->next = head;
    return nhead;
  }
};
// @lc code=end
