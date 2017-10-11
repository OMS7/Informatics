#include <bits/stdc++.h>
using namespace std;
void dfs(int s, vector<vector<int>> &g, vector<int> &ans, vector<bool> &vis) {
	vis[s] = true;
	ans.push_back(s);
	for (int to : g[s]) {
		if (vis[to]) continue;
		dfs(to, g, ans, vis);
		ans.push_back(s);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> ans;
	vector<bool> vis(n);
	dfs(0, g, ans, vis);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << " ";
	}
}
