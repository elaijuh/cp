// OJ: https://leetcode.com/problems/odd-even-linked-list/
// Author: github.com/elaijuh
// Time: O(n)
// Space: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* headNext = head->next;
    ListNode* o = head;
    ListNode* e = headNext;
    while (o->next && e->next) {
      o->next = o->next->next;
      o = o->next;
      e->next = e->next->next;
      e = e->next;
    }
    o->next = headNext;
    return head;
  }
};
static auto x = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();
