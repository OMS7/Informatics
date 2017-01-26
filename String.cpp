#include <iostream>
using namespace std;
class String {
	char *s;
	int sz;
	void initsize() {
		sz = strlen(s);
	}
public:
	String(char *a) {
		s = a;
		initsize();
	}
	String(char *a, int b) {
		s = a;
		sz = b;
	}
	String(String &a) {
		sz = a.size();
		s = a.get_cs();
	}
	void read() {
		cin >> s;
	}
	void print(char last = '\n') {
		cout << s << last;
	}
	int find(String &a) {
		for (int i = 0; i < a.size() - sz; i++) {
			if (a == substr(i, (int)a.size())) {
				return i;
			}
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
	bool empty() {
		return sz == 0;
	}
	char operator [] (int a) {
		return s[a];
	}
	String operator = (String &a) {
		sz = a.size();
		s = a.get_cs();
		return String(s, sz);
	}
};
bool operator == (String &a, String &b) {
	if (a.size() != b.size()) return 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}
bool operator != (String &a, String &b) {
	return !(a == b);
}
String concat(String &a, String &b) {
	int sz = a.size() + b.size();
	char *s = new char[sz];
	for (int i = 0; i < sz; i++) {
		if (i < a.size()) s[i] = a[i];
		else s[i] = b[i - a.size()];
	}
	a = String(s, sz);
	return a;
}
int main() {

}
