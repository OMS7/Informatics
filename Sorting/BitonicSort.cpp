#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
template <class T>
void bitseqsort(vector<T> &a, int l, int r, bool b) {
	if (l == r - 1) return;
	int m = (l + r) / 2;
	for (int i = l, j = m; j < r; i++, j++) {
		if (b ^ (a[i] > a[j])) swap(a[i], a[j]);
	}
	bitseqsort(a, l, m, b);
	bitseqsort(a, m, r, b);
}
template <class T>
void makebitonic(vector<T> &a, int l, int r) {
	if (r - l <= 1) return;
	int m = (l + r) / 2;
	makebitonic(a, l, m);
	bitseqsort(a, l, m, 0);
	makebitonic(a, m, r);
	bitseqsort(a, m, r, 1);
}
template <class T>
void bitsort(vector<T> &a, T inf) {
	int n = 1;
	while (n < a.size()) n *= 2;
	a.resize(n, inf);
	makebitonic(a, 0, n);
	bitseqsort(a, 0, n, 0);
	while (a.back() == inf && !a.empty()) a.pop_back();
}
template <class T>
bool check(vector<T> &init, vector<T> &ans) {
	sort(init.begin(), init.end());
	return init == ans;
}
int main() {
	freopen("time.txt", "w", stdout);
	for (int i = 1; i <= 203; i++) {
		string s = "Tests//test" + to_string(i) + ".txt";
		freopen(s.c_str(), "r", stdin);
		int n;
		cin >> n;
		vector<int> v(n);
		for (int j = 0; j < n; j++) scanf("%d", &v[j]);
		vector<int> q = v;
		int c1 = clock();
		bitsort(q, (int)2e9);
		int c2 = clock();
		printf("%d\n", c2 - c1);
		assert(check(v, q));
		fclose(stdin);
	}
}
