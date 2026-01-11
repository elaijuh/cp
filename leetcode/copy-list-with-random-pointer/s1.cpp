#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/

class Solution {
public:
	Node *copyRandomList(Node *head)
	{
		if (!head) return head;
		unordered_map<Node *, Node *> mp;

		Node *cur = head;
		Node *nhead = new Node(head->val);
		Node *ncur = nhead;
		mp[head] = nhead;
		cur = cur->next;
		while (cur) {
			Node *node = new Node(cur->val);
			mp[cur] = node;
			ncur->next = node;
			ncur = ncur->next;
			cur = cur->next;
		}
		cur = head;
		ncur = nhead;
		while (cur) {
			if (cur->random) ncur->random = mp[cur->random];
			cur = cur->next;
			ncur = ncur->next;
		}
		return nhead;
	}
};
