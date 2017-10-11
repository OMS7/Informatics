#include <bits/stdc++.h>
using namespace std;
void dfs(int s, vector<vector<int>> &g, vector<int> &c, int cur) {
	c[s] = cur;
	for (int to : g[s]) {
		if (c[to] == 0) {
			dfs(to, g, c, cur);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int> (m));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> c(n);
	int cur = 1;
	for (int i = 0; i < n; i++) {
		if (c[i] == 0) dfs(i, g, c, cur++);
	}
	for (int i = 0; i < n; i++) {
		cout << c[i] << " ";
	}
}
