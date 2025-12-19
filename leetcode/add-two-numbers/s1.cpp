#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *ans = new ListNode(0);
		ListNode *p = ans;
		int k = 0;
		while (l1 || l2 || k) {
			int d = k;
			if (l1) {
				d += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				d += l2->val;
				l2 = l2->next;
			}
			k = d / 10;
			ListNode *n = new ListNode(d % 10);
			p->next = n;
			p = p->next;
		}
		return ans->next;
	}
};
