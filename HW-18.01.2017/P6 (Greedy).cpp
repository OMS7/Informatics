#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int schedule(int n, vector<pii> &app) {
	sort(app.begin(), app.end());
	int r = app[0].first, ans = 1;
	for (int i = 1; i < n; i++) {
		if (app[i].second >= r) {
			ans++; r = app[i].first;
		}
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
	cout << schedule(n, v);
}
