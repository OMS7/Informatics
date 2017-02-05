#include <bits/stdc++.h>
using namespace std;
template <class T> class llist {
	struct elem {
		T val;
		elem *next = nullptr;
	};
	elem *first = nullptr, *last = nullptr;
	int sz = 0;
public:
	int size() {
		return sz;
	}
	bool empty() {
		return sz == 0;
	}
	void push_front(T a) {
		elem *e = new elem;
		e->val = a;
		if (first != nullptr) {
			e->next = first;
			swap(e, first);
		}
		else {
			e->next = nullptr;
			first = last = e;
		}
		sz++;
	}
	void push_back(T a) {
		elem *e = new elem;
		e->val = a;
		e->next = nullptr;
		if (last != nullptr) {
			last->next = e;
			swap(e, last);
		}
		else first = last = e;
		sz++;
	}
	T& front() {
		if (sz == 0) exit(EXIT_FAILURE);
		else return first->val;
	}
	T& back() {
		if (sz == 0) exit(EXIT_FAILURE);
		else return last->val;
	}
	bool pop_front() {
		if (sz == 0) return 0;
		if (first->next == nullptr) {
			first = last = nullptr;
		}
		else swap(first, first->next);
		sz--;
		return 1;
	}
	bool pop_back() {
		if (sz == 0) return 0;
		if (first == last) {
			first = last = nullptr;
		}
		else {
			elem *e = first;
			while (e->next != last) e = e->next;
			delete last->next;
			swap(last, e);
			last->next = nullptr;
		}
		sz--;
		return 1;
	}
	bool insert(int pos, int a) {
		if (pos < 0 || pos > sz) return 0;
		if (pos == sz) {
			push_back(a);
			return 1;
		}
		if (pos == 0) {
			push_front(a);
			return 1;
		}
		elem *e = new elem, *c1 = first;
		for (int i = 0; i < pos - 1; i++) c1 = c1->next;
		elem *c2 = c1->next;
		e->val = a;
		e->next = c2;
		c1->next = e;
		sz++;
		return 1;
	}
	bool erase(int pos) {
		if (pos < 0 || pos >= sz) return 0;
		if (pos == sz - 1) {
			pop_back();
			return 1;
		}
		if (pos == 0) {
			pop_front();
			return 1;
		}
		elem *c = first;
		for (int i = 0; i < pos - 1; i++) c = c->next;
		elem *n = c->next;
		c->next = n->next;
		delete n;
		sz--;
	}
	int find(int a) {
		elem* e = first;
		int ans = 0;
		while (e != nullptr && e->val != a) {
			e = e->next;
			ans++;
		}
		return ans;
	}
	void clear() {
		elem *e = first;
		while (e != nullptr) {
			elem *ec = e->next;
			delete e;
			e = ec;
		}
		first = last = nullptr;
		sz = 0;
	}
	void print(char p = '\n', char c = ' ') {
		elem *e = first;
		while (e != nullptr) {
			cout << e->val << c;
			e = e->next;
		}
		cout << p;
	}
	T& operator [] (int pos) {
		if (pos < 0 || pos >= sz) exit(EXIT_FAILURE);
		elem *a = first;
		for (int i = 0; i < pos; i++) a = a->next;
		return a->val;
	}
};
int main() {
	llist<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.print();
	d.insert(1, 5);
	d.print();
	d.erase(2);
	d.print();
	d.pop_front();
	d.pop_back();
	d.print();
	d.clear();
	d.push_front(1);
	d.push_front(2);
	d.push_front(3);
	d.push_front(4);
	d.print();
	cout << d.front() << " " << d.back() << "\n";
	cout << d[0] << " " << d[3] << "\n";
	d[1] = 5;
	d.print();
	d.erase(d.find(2));
	d.print();
	d.erase(d.find(10));
	d.print();
}
