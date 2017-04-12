#include <bits/stdc++.h>
using namespace std;
template <class T, class Y>
class Map {
	struct node {
		T key;
		Y inf;
		bool color;
		bool fict = 0;
		node *left, *right, *parent;
		node(T val, Y _inf, node* par) {
			key = val;
			inf = _inf;
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
	node* _insert(node* tree, T key, Y inf, node* parent) {
		if (tree == nullptr) {
			tree = new node(key, inf, parent);
			if (parent == nullptr) tree->color = 0;
			return tree;
		}
		if (key <= tree->key) tree->left = _insert(tree->left, key, inf, tree);
		else tree->right = _insert(tree->right, key, inf, tree);
		return balancing_insert(tree);
	}
	bool _find(node* tree, T key) {
		if (tree == nullptr) return 0;
		if (tree->key == key && !tree->fict) return 1;
		return (key <= tree->key) ? _find(tree->left, key) : _find(tree->right, key);
	}
	node* __find(node* tree, T key) {
		if (tree == nullptr) return 0;
		if (tree->key == key && !tree->fict) return tree;
		return (key <= tree->key) ? __find(tree->left, key) 
			: __find(tree->right, key);
	}
	void _replace(node* tree, T key, Y newval) {
		if (tree == nullptr) return;
		if (tree->key == key && !tree->fict) tree->inf = newval;
		else if (key <= tree->key) _replace(tree->left, key, newval);
		else _replace(tree->right, key, newval);
	}
	void _erase(node* tree, T key) {
		if (tree == nullptr) return;
		if (tree->key == key && !tree->fict) {
			tree->fict = 1;
			return;
		}
		if (tree->key <= key) _erase(tree->right, key);
		else _erase(tree->left, key);
	}
	/*node* balancing_erase(node* tree, node* newnode) {
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
	}	*/
	void _print(node* tree) {
		if (tree == nullptr) return;
		_print(tree->left);
		if (!tree->fict) cout << tree->key << " : " << tree->inf << endl;
		_print(tree->right);
	}
	void _clear(node* tree) {
		if (tree->left != nullptr) _clear(tree->left);
		if (tree->right != nullptr) _clear(tree->right);
		delete tree;
	}
public:
	Map() {
		root = nullptr;
		sz = 0;
	}
	~Map() {
		clear();
	}
	void insert(T key, Y val) {
		if (find(key)) _replace(root, key, val);
		else {
			root = _insert(root, key, val, nullptr);
			sz++;
		}
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
	void clear() {
		_clear(root);
		root = nullptr;
		sz = 0;
	}
	void print() {
		_print(root);
	}
	Y& operator [] (T key) {
		if (!find(key)) insert(key, 0);
		node* n = __find(root, key);
		return n->inf;
	}
};
int main() {
	Map<string, int> m;
	m["A"] = 1;
	m["B"] = 2;
	m["C"] = 3;
	m["ABCD"] = 1234;
	m.print();
	m["A"] = 2;
	m["B"] = 3;
	m.print();
	cout << m["A"] << " " << m["E"] << endl;
	m.print();
	cout << m.size() << endl;
	m.erase("A"); m.erase("B");
	m.print();
}
