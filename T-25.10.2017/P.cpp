#include <bits/stdc++.h>
using namespace std;
vector<int> ans;

bool bf(int s, vector<vector<int>> &g, vector<bool> &vis, vector<int> &ans) {
	ans.push_back(s);
	vis[s] = true;
	for (int to : g[s]) {
		if (ans.size() == g.size()) {
			if (ans[0] == to) {
				ans.push_back(to);
				return true;
			}
			else continue;
		}
		if (vis[to]) continue;
		if (bf(to, g, vis, ans)) return true;
	}
	/*
	if (ans.size() == g.size()) {
		for (int i = 0; i < g.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	*/
	vis[s] = false;
	ans.pop_back();
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<bool> vis(n);
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (bf(i, g, vis, ans)) {
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				cout << ans[i] << " ";
			}
			return 0;
		}
	}
	cout << "NO";
}
