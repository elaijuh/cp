/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int i = 0, s;
    ListNode* r = new ListNode(-1);
    ListNode* k = r;
    while (1) {
      if (l1 != NULL && l2 != NULL) {
        s = l1->val + l2->val + i;
        l1 = l1->next;
        l2 = l2->next;
      } else if (l1 == NULL && l2 != NULL) {
        s = l2->val + i;
        l2 = l2->next;
      } else if (l2 == NULL && l1 != NULL) {
        s = l1->val + i;
        l1 = l1->next;
      } else {
        if (i == 1) {
          ListNode* t = new ListNode(1);
          k->next = t;
        }
        break;
      }
      if (s >= 10) {
        s -= 10;
        i = 1;
      } else {
        i = 0;
      }
      ListNode* t = new ListNode(s);
      k->next = t;
      k = t;
    }
    return r->next;
  }
};
