/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (40.19%)
 * Likes:    2348
 * Dislikes: 118
 * Total Accepted:    246K
 * Total Submissions: 608.1K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 * Example 1:
 *
 *
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 *
 *
 * Example 2:
 *
 *
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
 protected:
  void mergeSort(ListNode** phead) {
    ListNode* head = *phead;
    ListNode* a;
    ListNode* b;
    if (!head || !(head->next)) return;
    split(head, &a, &b);  // 等分list成a,b
    mergeSort(&a);
    mergeSort(&b);
    *phead = merge(a, b);
  }
  void move(ListNode** dest, ListNode** src) {
    ListNode* p = *src;
    *src = p->next;
    p->next = *dest;
    *dest = p;
  }

  ListNode* merge(ListNode* a, ListNode* b) {
    ListNode header;
    ListNode* tail = &header;
    while (1) {
      if (!a) {
        tail->next = b;
        break;
      } else if (!b) {
        tail->next = a;
        break;
      }
      if (a->val <= b->val)
        move(&(tail->next), &a);
      else
        move(&(tail->next), &b);
      tail = tail->next;
    }
    return header.next;
  }
  void split(ListNode* head, ListNode** l, ListNode** r) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast) {
      fast = fast->next;
      if (fast) {
        slow = slow->next;
        fast = fast->next;
      }
    }
    *l = head;
    *r = slow->next;
    slow->next = nullptr;
  }

 public:
  ListNode* sortList(ListNode* head) {
    mergeSort(&head);
    return head;
  }
};
// @lc code=end
