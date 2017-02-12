#include <bits/stdc++.h>
using namespace std;
template <class T> class Vector {
	T *vec;
	int sz, cap;
	void upd(T val = 0) {
		T *vec2 = new T [cap];
		for (int i = 0; i < sz; i++) {
			vec2[i] = vec[i];
		}
		for (int i = sz; i < cap; i++) {
			vec2[i] = val;
		}
		swap(vec, vec2);
		delete vec2;
	}
public:
	Vector() {
		sz = cap = 0;
	}
	Vector(int a) {
		sz = 0;
		cap = a;
		upd();
		sz = cap;
	}
	Vector(int a, T b) {
		sz = 0;
		cap = a;
		upd(b);
		sz = cap;
	}
	int size() {
		return sz;
	}
	int capacity() {
		return cap;
	}
	bool empty() {
		return sz == 0;
	}
	void resize(int a) {
		cap = a;
		if (a < sz) sz = a;
		upd();
	}
	void resize(int a, T b) {
		cap = a;
		if (a < sz) sz = a;
		upd(b);
	}
	bool insert(int pos, T val) {
		if (pos < 0 || pos > sz) return 0;

	}
	T& front() {
		if (sz == 0) exit(EXIT_FAILURE);
		return vec[0];
	}
	T& back() {
		if (sz == 0) exit(EXIT_FAILURE);
		return vec[sz - 1];
	}
	void push_back(T a) {
		if (sz == cap) {
			if (cap != 0) cap *= 2;
			else cap++;
			upd();
		}
		vec[sz] = a;
		sz++;
	}
	bool pop_back() {
		if (sz == 0) return 0;
		sz--;
		if (cap / 2 >= sz && sz != 0) {
			cap /= 2;
			upd();
		}
	}
	void clear() {
		delete vec;
		sz = cap = 0;
	}
	T& operator [] (int pos) {
		if (pos < 0 || pos >= sz) exit(EXIT_FAILURE);
		return vec[pos];
	}
	void operator = (Vector<T> &b) {
		sz = b.size();
		cap = b.capacity();
		delete vec;
		vec = new T [cap];
		for (int i = 0; i < sz; i++) {
			vec[i] = b[i];
		}
	}
};
template <class T> void print(Vector<T> a, char last = '\n') {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
		if (a.size() - 1 != i) putchar(' ');
	}
	cout << last;
}
int main() {
	Vector<int> vec;
	for (int i = 0; i < 20; i++) vec.push_back(i);
	print(vec);
	Vector<int> vec2;
	vec2 = vec;
	while (!vec.empty()) {
		cout << vec.back() << " ";
		vec.pop_back();
	}
	cout << endl;
	vec2[1] = vec2[3] = 10;
	print(vec2);
	cout << vec2.front() << " " << vec2.back() << endl;
	cout << vec2.size() << " " << vec2.capacity() << endl;
	vec2.resize(5);
	print(vec2);
	Vector<double> vec3(8, 1.742);
	print(vec3);
}
