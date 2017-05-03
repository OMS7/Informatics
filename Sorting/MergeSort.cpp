#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std; template <class T>
void merge(vector<T> &v, int l, int r) {
	int m = (l + r) / 2;
	int cl = l, cr = m, cur = 0;
	vector<T> ans(r - l);
	while (cl < m && cr < r) {
		if (v[cl] < v[cr]) ans[cur++] = v[cl++];
		else ans[cur++] = v[cr++];
	}
	while (cl < m) ans[cur++] = v[cl++];
	while (cr < r) ans[cur++] = v[cr++];
	for (int i = 0; i < r - l; i++)
		v[i + l] = ans[i];
}
template <class T>
void _mergesort(vector<T> &v, int l, int r) {
	if (l >= r - 1) return;
	int m = (l + r) / 2;
	_mergesort(v, l, m);
	_mergesort(v, m, r);
	merge(v, l, r);
}
template <class T>
void mergesort(vector<T> &v) {
	_mergesort(v, 0, v.size());
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
		mergesort(v);
		int c2 = clock();
		assert(check(q, v));
		printf("%d\n", c2 - c1);
		fclose(stdin);
	}
}
