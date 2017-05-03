#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
template <class T>
void _quicksort(vector<T> &v, int l, int r) {
	int z = v[(l + r) / 2];
	int ll = l, rr = r;
	while (ll <= rr) {
		while (v[ll] < z) ll++;
		while (v[rr] > z) rr--;
		if (ll <= rr) swap(v[ll++], v[rr--]);
	}
	if (l < rr) _quicksort(v, l, rr);
	if (ll < r) _quicksort(v, ll, r);
}
template <class T>
void quicksort(vector<T> &a) {
	_quicksort(a, 0, a.size() - 1);
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
		quicksort(v);
		int c2 = clock();
		assert(check(q, v));
		printf("%d\n", c2 - c1);
		fclose(stdin);
	}
}
