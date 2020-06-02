// OJ: https://leetcode.com/problems/delete-node-in-a-linked-list/
// Author: github.com/elaijuh
// Time: O(N)
// Space: O()
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
  void deleteNode(ListNode* node) {
    ListNode* pred = node;
    node = node->next;
    while (node) {
      swap(pred->val, node->val);
      if (node->next) pred = node;
      node = node->next;
    }
    pred->next = NULL;
  }
};
