#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
	vector<int> v;
	int cap;
	size_t head = 0;

public:
	MyCircularQueue(int k)
	{
		v.reserve(k);
		cap = k;
	}

	bool enQueue(int value)
	{
		if (!isFull()) {
			v.push_back(value);
			return true;
		}
		return false;
	}

	bool deQueue()
	{
		if (!isEmpty()) {
			head++;
			return true;
		}
		return false;
	}

	int Front()
	{
		return isEmpty() ? -1 : v[head];
	}

	int Rear()
	{
		return isEmpty() ? -1 : v.back();
	}

	bool isEmpty()
	{
		return size() == 0;
	}

	bool isFull()
	{
		return size() - cap >= 0;
	}

	int size()
	{
		return v.size() - head;
	}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 *
