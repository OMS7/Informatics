#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long double db;
pair<vector<db>, db> Continuous_knapsack(int w, vector<pii> &v) {
	int n = v.size();
	vector<pair<db, int>> adv(n);
	for (int i = 0; i < n; i++) {
		adv[i] = { v[i].second / v[i].first, i };
	}
	sort(adv.begin(), adv.end());
	reverse(adv.begin(), adv.end());
	vector<db> ans1(n);
	db ans2 = 0;
	for (int i = 0; i < n; i++) {
		int ind = adv[i].second;
		int ww = v[ind].first, pp = v[ind].second;
		if (w >= ww) ans1[ind] = 1, ans2 += pp, w -= ww;
		else {
			db d = (db)w / ww;
			ans1[ind] = d;
			ans2 += d * pp;
			break;
		}
	}
	return { ans1, ans2 };
}
int main() {
	int w, n;
	cin >> w >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
	pair<vector<db>, db> ans = Continuous_knapsack(w, v);
	cout << setprecision(20);
	for (int i = 0; i < n; i++) cout << ans.first[i] << ' ';
	cout << endl << ans.second;
}
