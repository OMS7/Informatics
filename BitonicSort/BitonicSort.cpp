#include <bits/stdc++.h>
using namespace std;
void bitseqsort(vector<int> &a, int l, int r, bool b) {
	if (l == r - 1) return;
	int m = (l + r) / 2;
	for (int i = l, j = m; j < r; i++, j++) {
		if (b ^ (a[i] > a[j])) swap(a[i], a[j]);
	}
	bitseqsort(a, l, m, b);
	bitseqsort(a, m, r, b);
}
void makebitonic(vector<int> &a, int l, int r) {
	if (r - l <= 1) return;
	int m = (l + r) / 2;
	makebitonic(a, l, m);
	bitseqsort(a, l, m, 0);
	makebitonic(a, m, r);
	bitseqsort(a, m, r, 1);
}
void bitsort(vector<int> &a) {
	int n = 1;
	while (n < a.size()) n *= 2;
	a.resize(n, 2e9);
	makebitonic(a, 0, n);
	bitseqsort(a, 0, n, 0);
	while (a.back() == 2e9 && !a.empty()) a.pop_back();
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	bitsort(a);
	for (int i = 0; i < n; i++) cout << a[i] << " ";
}
