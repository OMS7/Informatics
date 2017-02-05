#include <bits/stdc++.h>
using namespace std;
template <class T> class Stack {
	struct elem {
		T val;
		elem *prev = nullptr;
	};
	elem *last = nullptr;
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
		e->prev = last;
		if (last != nullptr) swap(e, last);
		else last = e;
		sz++;
	}
	T& top() {
		if (sz == 0) exit(EXIT_FAILURE);
		else return last->val;
	}
	bool pop() {
		if (sz == 0) return 0;
		if (sz == 1) last = nullptr;
		else {
			elem *e = last->prev;
			swap(last, e);
			delete e;
		}
		sz--;
		return 1;
	}
	void clear() {
		elem *e = last;
		while (last != nullptr) {
			elem *ec = last->prev;
			delete e;
			e = ec;
		}
		last = nullptr;
		sz = 0;
	}
};
int main() {
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}
