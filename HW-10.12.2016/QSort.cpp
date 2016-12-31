#include <bits/stdc++.h>
using namespace std;
template<class T>
void QuickSort(vector<T> &v, int l, int r) {
	T z = v[(l + r) / 2];
	int ll = l, rr = r;
	while (ll <= rr) {
		while (v[ll] > z) ll++;
		while (v[rr] < z) rr--;
		if (ll <= rr) swap(v[ll++], v[rr--]);
	}
	if (l < rr) QuickSort(v, l, rr);
	if (ll < r) QuickSort(v, ll, r);
}
int main() {
	int n;
	cin >> n;
	vector<double> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	QuickSort(v, 0, v.size() - 1);
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
}
