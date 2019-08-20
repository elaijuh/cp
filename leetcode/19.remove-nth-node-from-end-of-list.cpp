/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p1 = head;
    ListNode* p2 = head;  // n+1 from the end
    int i = 0;
    while (p1->next != nullptr) {
      p1 = p1->next;
      i++;
      if (i > n) p2 = p2->next;
    }
    if (i < n) {
      return head->next;
    } else {
      p2->next = p2->next->next;
      return head;
    }
  }
};
