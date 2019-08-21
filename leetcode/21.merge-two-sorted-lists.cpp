/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *p1 = l1, *p2 = l2;
    ListNode* p = new ListNode(-1);
    ListNode* pp = p;
    while (p1 != nullptr && p2 != nullptr) {
      if (p1->val < p2->val) {
        p->next = p1;
        p = p->next;
        p1 = p1->next;
      } else {
        p->next = p2;
        p = p->next;
        p2 = p2->next;
      }
    }
    while (p1 != nullptr) {
      p->next = p1;
      p = p->next;
      p1 = p1->next;
    }
    while (p2 != nullptr) {
      p->next = p2;
      p = p->next;
      p2 = p2->next;
    }
    return pp->next;
  }
};
