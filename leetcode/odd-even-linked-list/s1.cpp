#include <bits/stdc++.h>
using namespace std;

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
	ListNode *oddEvenList(ListNode *head)
	{
		if (!head || !head->next || !head->next->next) return head;
		ListNode *po = head;
		ListNode *pe = head->next;
		ListNode *pt = head->next;
		while (po->next && pe->next) {
			po->next = pe->next;
			po = po->next;
			pe->next = po->next;
			pe = pe->next;
		}
		po->next = pt;
		return head;
	}
};
