#include <bits/stdc++.h>
using namespace std;
// binary search tree
template <class T> class bstree {
	struct elem {
		T val;
		elem *left = nullptr, *right = nullptr, *parent = nullptr;
	};
	elem* minimum1(elem *e) {
		elem *cur = e;
		while (cur->left != nullptr) {
			cur = cur->left;
		}
		return cur;
	}
	void PrintInOrder1(elem *cur) {
		if (cur == nullptr) return;
		PrintInOrder1(cur->left);
		cout << cur->val << " ";
		PrintInOrder1(cur->right);
	}
	void PrintPreOrder1(elem *cur) {
		if (cur == nullptr) return;
		cout << cur->val << " ";
		PrintPreOrder1(cur->left);
		PrintPreOrder1(cur->right);
	}
	void PrintPostOrder1(elem *cur) {
		if (cur == nullptr) return;
		PrintPostOrder1(cur->left);
		PrintPostOrder1(cur->right);
		cout << cur->val << " ";
	}
	void isbalance(elem *cur, int h, int &maxh) {
		if (cur == nullptr) return;
		maxh = max(maxh, h);
		isbalance(cur->left, h + 1, maxh);
		isbalance(cur->right, h + 1, maxh);
	}
	elem *root = nullptr;
	int sz = 0;
public:
	int size() {
		return sz;
	}
	bool empty() {
		return sz == 0;
	}
	void insert(T a) {
		if (root == nullptr) {
			root = new elem;
			root->val = a;
			return;
		}
		elem *cur = root;
		while (1) {
			if (a <= cur->val) {
				if (cur->left == nullptr) {
					cur->left = new elem;
					cur->left->val = a;
					cur->left->parent = cur;
					break;
				}
				else cur = cur->left;
			}
			else if (cur->right == nullptr) {
				cur->right = new elem;
				cur->right->val = a;
				cur->right->parent = cur;
				break;
			}
			else cur = cur->right;
		}
		sz++;
	}
	bool find(T a) {
		elem *cur = root;
		while (cur != nullptr) {
			if (a < cur->val) cur = cur->left;
			else if (a == cur->val) return 1;
			else cur = cur->right;
		}
		return 0;
	}
	T minimum() {
		if (root == nullptr) exit(EXIT_FAILURE);
		return minimum1(root)->val;
	}
	T maximum() {
		if (root == nullptr) exit(EXIT_FAILURE);
		elem *cur = root;
		while (cur->right != nullptr) {
			cur = cur->right;
		}
		return cur->val;
	}
	bool erase(T a) {
		elem *cur = root;
		while (cur != nullptr) {
			if (a < cur->val) cur = cur->left;
			else if (a == cur->val) break;
			else cur = cur->right;
		}
		if (cur == nullptr) return 0;
		if (cur->left == nullptr && cur->right == nullptr) {
			if (cur->parent->left == cur) {
				cur->parent->left = nullptr;
			}
			else cur->parent->right = nullptr;
		}
		else if (cur->left == nullptr) {
			if (cur->parent->left == cur) {
				cur->parent->left = cur->right;
			}
			else cur->parent->right = cur->right;
			cur->right->parent = cur->parent;
			delete cur;
		}
		else if (cur->right == nullptr) {
			if (cur->parent->left == cur) {
				cur->parent->left = cur->left;
			}
			else cur->parent->right = cur->left;
			cur->left->parent = cur->parent;
			delete cur;
		}
		else {
			elem *e = minimum1(cur->right);
			cur->val = e->val;
			if (e->parent->left == cur) {
				e->parent->left = nullptr;
			}
			else e->parent->right = nullptr;
		}
		sz--;
		return 1;
	}
	void PrintInOrder() {
		PrintInOrder1(root);
	}
	void PrintPreOrder() {
		PrintPreOrder1(root);
	}
	void PrintPostOrder() {
		PrintPostOrder1(root);
	}
	void clear() {
		root = nullptr;
		sz = 0;
	}
	bool balance() {
		elem *cur = root;
		int maxh = 0;
		isbalance(cur, 1, maxh);
		if (log2(sz) >= maxh) return 1;
		else return 0;
	}
};
int main() {
	bstree<int> bst;
	bst.insert(5);
	bst.insert(1);
	bst.insert(3);
	bst.insert(2);
	bst.insert(6);
	bst.insert(4);
	cout << bst.balance() << endl; 
	bst.PrintInOrder(); cout << endl;
	bst.PrintPreOrder(); cout << endl;
	bst.PrintPostOrder(); cout << endl;
	cout << bst.minimum() << endl;
	cout << bst.maximum() << endl;
	cout << bst.erase(1) << " "
		 << bst.erase(2) << " "
		 << bst.erase(5) << endl;
	cout << bst.find(1) << " "
		 << bst.find(3) << " " 
		 << bst.find(6) << endl;
	bst.insert(1);
	bst.insert(2);
	bst.insert(3);
	bst.PrintInOrder(); cout << endl;
	bst.PrintPreOrder(); cout << endl;
	bst.PrintPostOrder(); cout << endl;
	bst.clear();
}
