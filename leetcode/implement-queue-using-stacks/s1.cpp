#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
	stack<int> l, r;

	MyQueue()
	{
	}

	void push(int x)
	{
		l.push(x);
	}

	int pop()
	{
		while (!l.empty()) {
			r.push(l.top());
			l.pop();
		}
		int top = r.top();
		r.pop();
		while (!r.empty()) {
			l.push(r.top());
			r.pop();
		}
		return top;
	}

	int peek()
	{
		while (!l.empty()) {
			r.push(l.top());
			l.pop();
		}
		int top = r.top();
		while (!r.empty()) {
			l.push(r.top());
			r.pop();
		}
		return top;
	}

	bool empty()
	{
		return l.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
