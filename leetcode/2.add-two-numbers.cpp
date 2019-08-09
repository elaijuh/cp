/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int k = 0;
    ListNode *ans = new ListNode(-1);
    ListNode *t = ans;
    while (l1 != nullptr && l2 != nullptr) {
      ListNode *node = new ListNode((l1->val + l2->val + k) % 10);
      k = (l1->val + l2->val + k) / 10;
      l1 = l1->next;
      l2 = l2->next;
      t->next = node;
      t = node;
    }
    while (l1 != nullptr) {
      ListNode *node = new ListNode((l1->val + k) % 10);
      k = (l1->val + k) / 10;
      l1 = l1->next;
      t->next = node;
      t = node;
    }
    while (l2 != nullptr) {
      ListNode *node = new ListNode((l2->val + k) % 10);
      k = (l2->val + k) / 10;
      l2 = l2->next;
      t->next = node;
      t = node;
    }
    if (k == 1) {
      ListNode *node = new ListNode(1);
      t->next = node;
    }
    return ans->next;
  }
};
