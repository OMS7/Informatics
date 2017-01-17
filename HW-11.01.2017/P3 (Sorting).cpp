#include <bits/stdc++.h>
using namespace std;
vector<int> incredible_sort(vector<int> &v, int k) {
	vector<int> kk(k + 1);
	for (int i = 0; i < v.size(); i++) kk[v[i]]++;
	vector<int> ans;
	for (int i = k; i >= 0; i--) {
		for (int q = 0; q < kk[i]; q++) ans.push_back(i);
	}
	return ans;
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	v = incredible_sort(v, k);
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
}
