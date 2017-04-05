#include <bits/stdc++.h>
using namespace std;
template <class T>
class rbtree {
	struct node {
		T key;
		bool color;
		node *left, *right, *parent;
		node(T val, node* par) {
			key = val;
			color = 1;
			parent = par;
			left = right = nullptr;
		}
	};
	node *root;
	int sz;
	node* rotate_right(node* tree) {
		node* left = tree->left;
		tree->left = left->right;
		left->right = tree;
		left->parent = tree->parent;
		tree->parent = left;
		return left;
	}
	node* rotate_left(node* tree) {
		node* right = tree->right;
		tree->right = right->left;
		right->left = tree;
		right->parent = tree->parent;
		tree->parent = right;
		return right;
	}
	node* balancing_insert(node* tree) {
		if (tree->left != nullptr && tree->left->color) {
			if ((tree->left->left != nullptr && tree->left->left->color)
				|| (tree->left->right != nullptr && tree->left->right->color)) {
				if (tree->right != nullptr && tree->right->color) {
					tree->left->color = 0;
					tree->right->color = 0;
					tree->color = 1;
				}
				else {
					tree = rotate_right(tree);
					tree->color = 0;
					tree->right->color = 1;
				}
			}
		}
		if (tree->right != nullptr && tree->right->color) {
			if ((tree->right->left != nullptr && tree->right->left->color)
				|| (tree->right->right != nullptr && tree->right->right->color)) {
				if (tree->left != nullptr && tree->left->color) {
					tree->left->color = 0;
					tree->right->color = 0;
					tree->color = 1;
				}
				else {
					tree = rotate_left(tree);
					tree->color = 0;
					tree->left->color = 1;
				}
			}
		}
		if (tree->parent == nullptr) tree->color = 0;
		return tree;
	}
	node* _insert(node* tree, T key, node* parent) {
		if (tree == nullptr) {
			tree = new node(key, parent);
			if (parent == nullptr) tree->color = 0;
			return tree;
		}
		if (key < tree->key) tree->left = _insert(tree->left, key, tree);
		else tree->right = _insert(tree->right, key, tree);
		return balancing_insert(tree);
	}
	bool _find(node* tree, T key) {
		if (tree == nullptr) return 0;
		if (tree->key == key) return 1;
		return (key < tree->key) ? _find(tree->left, key) : _find(tree->right, key);
	}
	node* balancing_erase(node* tree, node* newnode) {
		if (tree->left == newnode) {
			if (tree->right->color) {
				tree = rotate_left(tree);
				tree->color = 0;
				tree->left->color = 1;
				tree->left = balancing_erase(tree->left, newnode);
			}
			else if ((tree->right->left == nullptr 
				|| tree->right->left->color == 1)
				&& (tree->right->right == nullptr
					|| tree->right->right->color == 1)) {
				tree->color = 0;
				tree->right->color = 1;
				
			}
			else if ((tree->right->left != nullptr &&
				tree->right->left->color == 1) &&
				(tree->right->right == nullptr ||
					tree->right->right->color == 0)) {
				tree->right = rotate_right(tree->right);
				tree->color = 0;
				tree->right->color = 1;
			}
			else if (tree->right->right != nullptr &&
				tree->right->right->color == 1) { 
				tree->right->color = tree->color;
				tree->color = 0;
				tree->right->right->color = 0;
				tree = rotate_left(tree);
			}
		}
		else if (tree->right == newnode) {
			if (tree->left->color) {
				tree = rotate_right(tree);
				tree->color = 0;
				tree->right->color = 1;
				tree->right = balancing_erase(tree->right, newnode);
			}
			else if ((tree->left->left == nullptr
				|| tree->left->left->color == 1)
				&& (tree->left->right == nullptr
					|| tree->left->right->color == 1)) {
				tree->color = 0;
				tree->left->color = 1;
			}
			else if ((tree->left->left != nullptr &&
				tree->left->left->color == 1) &&
				(tree->left->right == nullptr ||
					tree->left->right->color == 0)) {
				tree->left = rotate_left(tree->left);
				tree->color = 0;
				tree->left->color = 1;
			}
			else if (tree->left->right != nullptr &&
				tree->left->right->color == 1) {
				tree->left->color = tree->color;
				tree->color = 0;
				tree->left->right->color = 0;
				tree = rotate_right(tree);
			}
		}
		return tree;
	}
	void _erase2(node* &tree) {
		node* parent = tree->parent;
		bool b = tree->color;
		if (tree->left == nullptr && tree->right == nullptr) {
			tree = nullptr;
		}
		else if (tree->left != nullptr) {
			tree = tree->left;
			tree->parent = parent;
		}
		else {
			tree = tree->right;
			tree->parent = parent;
		}
		if (!b) {
			if (tree != nullptr && tree->color) tree->color = 0;
			else parent = balancing_erase(parent, tree);
		}
	}
	void _erase(node* &tree, T key) {
		if (tree->key == key) {
			if (tree->left == nullptr || tree->right == nullptr) {
				_erase2(tree);
			}
			else {
				node* n = getmin(tree->right);
				swap(n->key, tree->key); 
				_erase2(n);
			}
		}
		else if (tree->key < key) _erase(tree->right, key);
		else _erase(tree->left, key);
	}
	node* getmin(node* tree) {
		if (tree->left != nullptr) return getmin(tree->left);
		return tree;
	}	
	void _print(node* tree) {
		if (tree == nullptr) return;
		_print(tree->left);
		cout << tree->key << " ";
		_print(tree->right);
	}
	void _clear(node* tree) {
		if (tree->left != nullptr) _clear(tree->left);
		if (tree->right != nullptr) _clear(tree->right);
		delete tree;
	}
	node* getmax(node* tree) {
		if (tree->right == nullptr) return tree;
		return getmax(tree->right);
	}
	void _upper_bound(node* tree, T key, T &ans) {
		if (tree == nullptr) return;
		if (key < tree->key) {
			ans = min(ans, tree->key);
			_upper_bound(tree->left, key, ans);
		}
		else _upper_bound(tree->right, key, ans);
	}
	void _get_all(node* tree, vector<T> &v) {
		if (tree == nullptr) return;
		_get_all(tree->left);
		v.push_back(tree->key);
		_get_all(tree->right);
	}
public:
	rbtree() {
		root = nullptr;
		sz = 0;
	}
	~rbtree() {
		clear();
	}
	void insert(T key) {
		if (find(key)) return;
		root = _insert(root, key, nullptr);
		sz++;
	}
	int size() {
		return sz;
	}
	bool empty() {
		return sz == 0;
	}
	bool find(T key) {
		return _find(root, key);
	}
	bool erase(T key) {
		if (!find(key)) return 0;
		_erase(root, key);
		sz--;
		return 1;
	}
	void merge(const rbtree &rb) {
		vector<T> v = rb.get_all();
		for (int i = 0; i < v.size(); i++) insert(v[i]);
	}
	void intersect(const rbtree &rb) {
		vector<T> v = get_all();
		for (int i = 0; i < v.size(); i++) {
			if (!rb.find(v[i])) erase(v[i]);
		}
	}
	vector<T> get_all() {
		vector<T> ans;
		_get_all(root, ans);
		return ans;
	}
	void clear() {
		_clear(root);
		root = nullptr;
		sz = 0;
	}
	void print() {
		_print(root);
	}
	T upper_bound(T key) {
		if (root == nullptr) return key - 1;
		T ans = getmax(root)->key;
		if (ans <= key) return key - 1;
		_upper_bound(root, key, ans);
		return ans;
	}
	T lower_bound(T key) {
		if (find(key)) return key;
		return upper_bound(key);
	}
};
int main() {
	rbtree<int> rb;
	for (int i = 0; i < 10; i++) rb.insert(i + 1);
	rb.print(); cout << endl;
	rb.erase(1); rb.erase(5);
	rb.print(); cout << endl;
	cout << rb.size() << " " << rb.empty() << endl;
	rb.erase(3);
	rb.print(); cout << endl;
	cout << "upper_bound 5 : " << rb.upper_bound(5) << endl;
	cout << "upper_bound 0 : " << rb.upper_bound(0) << endl;
	cout << "upper_bound 2 : " << rb.upper_bound(2) << endl;
	cout << "lower_bound 2 : " << rb.lower_bound(2) << endl;
	cout << "lower_bound 3 : " << rb.lower_bound(3) << endl;
	rb.clear();
	const int N = 30;
	int a[N];
	for (int i = 0; i < N; i++) a[i] = rand() % 10;
	random_shuffle(a, a + N);
	cout << "sort:" << endl;
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
		rb.insert(a[i]);
	}
	cout << endl;
	rb.print();
}
