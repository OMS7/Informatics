#include <bits/stdc++.h>
using namespace std;
template<class T>
T kthElement(vector<T> &v, int k) {
	int l = 0, r = v.size() - 1;
	while (1) {
		T z = v[(l + r) / 2];
		int ll = l, rr = r;
		while (ll <= rr) {
			while (v[ll] < z) ll++;
			while (v[rr] > z) rr--;
			if (ll <= rr) swap(v[ll++], v[rr--]);
		}
		if (k < ll && k > rr) return v[ll - 1];
		if (k >= ll) l = ll;
		else r = rr;
	}
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << kthElement(v, k - 1);
}
