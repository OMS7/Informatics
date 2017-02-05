#include <bits/stdc++.h>
using namespace std;
template <class T> class Queue {
	struct elem {
		T val;
		elem *next = nullptr, *prev = nullptr;
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
	void push(T a) {
		elem *e = new elem;
		e->val = a;
		e->prev = nullptr;
		if (first != nullptr) {
			e->next = first;
			first->prev = e;
			swap(e, first);
		}
		else {
			e->next = nullptr;
			first = last = e;
		}
		sz++;
	}
	T& front() {
		if (sz == 0) exit(EXIT_FAILURE);
		else return first->val;
	}
	bool pop() {
		if (sz == 0) return 0;
		if (first->next == nullptr) {
			first = last = nullptr;
		}
		else {
			delete first->prev;
			swap(first, first->next);
			first->prev = nullptr;
		}
		sz--;
		return 1;
	}
	void clear() {
		elem *e = first;
		while (e != nullptr) {
			delete e->prev;
			e = e->next;
		}
		first = last = nullptr;
		sz = 0;
	}
};
int main() {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	} 
}
