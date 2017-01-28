#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
class String {
	char *s;
	int sz, cap;
	void expansion() {
		cap *= 2;
		char *s2 = new char[cap];
		for (int i = 0; i < sz; i++) {
			s2[i] = s[i];
		}
		delete[] s;
		s = s2;
	}
public:
	String() {
		sz = 0;
		cap = 0;
	}
	String(char *a) {
		s = a;
		sz = strlen(s);
		cap = sz;
	}
	String(char *a, int b) {
		s = a;
		sz = cap = b;
	}
	String(int a) {
		s = new char[a];
		sz = a;
		cap = sz;
	}
	String(String &a) {
		sz = cap = a.size();
		s = a.get_cs();
	}
	void read() {
		char c = 0;
		while (c != '\n') {
			c = getchar();
			if (sz == cap) expansion();
			s[sz] = c;
			sz++;
		}
	}
	void print(char last = '\n') {
		for (int i = 0; i < sz; i++) {
			putchar(s[i]);
		}
		putchar(last);
	}
	int find(String &a) {
		for (int i = 0; i < a.size() - sz; i++) {
			if (a == substr(i, (int)a.size())) return i;
		}
		return -1;
	}
	String substr(int start, int num) {
		char *q = new char[num];
		for (int i = start, j = 0; i < start + num; i++, j++) {
			q[j] = s[i];
		}
		return String(q, num);
	}
	char* get_cs() {
		return s;
	}
	int get(int a) {
		return s[a];
	}
	void set(int a, char val) {
		s[a] = val;
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
	void push_back(char c) {
		if (sz == cap) expansion();
		s[sz] = c;
		sz++;
	}
	void pop_back() {
		sz--;
	}
	char& back() {
		return s[sz - 1];
	}
	char& operator [] (int a) {
		return s[a];
	}
	bool operator == (String &a) const {
		if (sz != a.size()) return 0;
		for (int i = 0; i < sz; i++) {
			if (s[i] != a[i]) return 0;
		}
		return 1;
	}
	String operator = (String &a) {
		sz = cap = a.size();
		s = a.get_cs();
		return String(s, sz);
	}
	String operator = (char *a) {
		sz = cap = strlen(a);
		s = a;
	}
	bool operator != (String &a) const {
		return !(*this == a);
	}
};
String concat(String &a, String &b) {
	int sz = a.size() + b.size();
	char *s = new char[sz];
	for (int i = 0; i < sz; i++) {
		if (i < a.size()) s[i] = a[i];
		else s[i] = b[i - a.size()];
	}
	return String(s, sz);
}
String operator + (String &a, String &b) {
	return concat(a, b);
}
int main() {
	String s1("Hello "), s2("world"), s3 = "a";
	s1.print(':'); cout << s1.size() << " " <<
		s1.capacity() << " " << s1.back() << endl;
	s2.print(':'); cout << s2.size() << " " <<
		s2.capacity() << " " << s2.back() << endl;
	s3.print(':'); cout << s3.size() << " " <<
		s3.capacity() << " " << s3.back() << endl;
	s1 = s1 + s2;
	s1.print();
	s1.push_back('a');
	s1.push_back('b');
	s1.push_back('c');
	s1.print();
	cout << (s1 == s3) << endl;
	cout << (s2 != s3) << endl;
	s1.pop_back();
	s1.print(' ');
	s1.substr(1, 3).print();
	s1[0] = s1[1] = '?';
	s1.print();
	String s5;
	s5.push_back('S');
	s5.push_back('t');
	s5.push_back('r');
	s5.push_back('i');
	s5.push_back('n');
	s5.push_back('g');
	s5.print();
}
