#include <iostream>

using namespace std;

class BST {
	struct node {
		int item;
		struct node *left;
		struct node *right;
		node(int item, node *left = nullptr, node *right = nullptr) : item(item) {}
	};

	node *root;

	node *find(int x, node *t)
	{
		if (t == nullptr)
			return t;
		else if (x < t->item)
			return find(x, t->left);
		else if (x > t->item)
			return find(x, t->right);
		else
			return t;
	}

	node *find_min(node *t)
	{
		if (t->left == nullptr)
			return t;
		else
			return find_min(t->left);
	}

	node *find_max(node *t)
	{
		if (t->right == nullptr)
			return t;
		else
			return find_max(t->right);
	}

	node *insert(int x, node *t)
	{
		if (t == nullptr) {
			t = new node(x);
		}
		else if (x < t->item) {
			t->left = insert(x, t->left);
		}
		else if (x > t->item) {
			t->right = insert(x, t->right);
		}
		return t;
	}

	node *erase(int x, node *t)
	{
		node *i;
		if (t == nullptr)
			return t;
		else if (x < t->item)
			t->left = erase(x, t->left);
		else if (x > t->item)
			t->right = erase(x, t->right);
		else if (t->left && t->right) {
			i = find_min(t->right);
			t->item = i->item;
			t->right = erase(t->item, t->right);
		}
		else {
			i = t;
			if (t->left == nullptr)
				t = t->right;
			else if (t->right == nullptr)
				t = t->left;
			delete i;
		}
		return t;
	}

	void inorder(node *t)
	{
		if (t == nullptr) return;
		inorder(t->left);
		cout << t->item << endl;
		inorder(t->right);
	}

public:
	BST() { root = nullptr; }
	~BST() {}

	void find(int x)
	{
		node *i = find(x, root);
		cout << "find ";
		if (i == nullptr)
			cout << "null" << endl;
		else
			cout << i->item << endl;
	}

	void find_min()
	{
		node *i = find_min(root);
		cout << "min: " << i->item << endl;
	}

	void find_max()
	{
		node *i = find_max(root);
		cout << "max: " << i->item << endl;
	}

	void insert(int x) { root = insert(x, root); }
	void erase(int x)
	{
		root = erase(x, root);
		cout << "erase: " << x << endl;
	}

	void display() { inorder(root); }
};

int main()
{
	BST t;
	t.insert(2);
	t.insert(4);
	t.insert(10);
	t.insert(6);
	t.insert(3);
	t.display();
	t.find(7);
	t.find(3);
	t.find_min();
	t.find_max();
	t.erase(3);
	t.display();
	return 0;
}
