#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<int> LDS(vector<int> &v) {
	int n = v.size();
	vector<int> d(n + 1, -1e9), ind(n + 1, -1), p(n, -1);
	d[0] = 1e9;
	for (int i = 0; i < n; i++) {
		int u = upper_bound(d.begin(), d.end(), v[i], greater<int>()) - d.begin();
		if (v[i] > d[u] && v[i] <= d[u - 1]) {
			d[u] = v[i];
			ind[u] = i;
			p[i] = ind[u - 1];
		}
	}
	int q = 0;
	while (q <= n && d[q] != -1e9) q++;
	q--; q = ind[q];
	vector<int> ret;
	while (q != -1) {
		ret.push_back(q);
		q = p[q];
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
vector<int> solve(vector<pii> &seg) {
	map<pii, int> conf;
	for (int i = 0; i < seg.size(); i++) {
		conf[{ seg[i].first, seg[i].second }] = i + 1;
	}
	sort(seg.begin(), seg.end());
	auto g = unique(seg.begin(), seg.end());
	seg.erase(g, seg.end());
	vector<int> perm;
	for (int i = 0; i < seg.size(); i++) {
		perm.push_back(seg[i].second);
	}
	vector<int> ans = LDS(perm), ret;
	for (int i = 0; i < ans.size(); i++) {
		ret.push_back(conf[seg[ans[i]]]);
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
	vector<int> ans = solve(v);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}
