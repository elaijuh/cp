/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (39.97%)
 * Likes:    518
 * Dislikes: 542
 * Total Accepted:    175.5K
 * Total Submissions: 438.4K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list using insertion sort.
 *
 *
 *
 *
 *
 * A graphical example of insertion sort. The partial sorted list (black)
 * initially contains only the first element in the list.
 * With each iteration one element (red) is removed from the input data and
 * inserted in-place into the sorted list
 *
 *
 *
 *
 *
 * Algorithm of Insertion Sort:
 *
 *
 * Insertion sort iterates, consuming one input element each repetition, and
 * growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data,
 * finds the location it belongs within the sorted list, and inserts it
 * there.
 * It repeats until no input elements remain.
 *
 *
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
 private:
  ListNode* nheader;

 protected:
  ListNode* search(int const& e) {
    ListNode* p = nheader;
    while (p->next) {
      if (p->next->val >= e) break;
      p = p->next;
    }
    return p;
  }
  void insert(ListNode* p, ListNode* q) {
    q->next = p->next;
    p->next = q;
  }
  void insertionSort(ListNode* head) {
    ListNode* p = head;
    while (p) {
      ListNode* q = p;
      int e = p->val;
      p = p->next;
      insert(search(e), q);
    }
  }

 public:
  ListNode* insertionSortList(ListNode* head) {
    nheader = new ListNode;
    insertionSort(head);
    return nheader->next;
  }
};
// @lc code=end
