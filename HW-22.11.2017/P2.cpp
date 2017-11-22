#include <bits/stdc++.h>
using namespace std;

class Bridges {
	void dfs(int s, int p, int &t, vector<vector<int>> &g, vector<int> &tin,
		vector<int> &up, vector<pair<int, int>> &ans) {
		tin[s] = up[s] = t++;
		for (int to : g[s]) {
			if (p == to) continue;
			if (!tin[to]) {
				dfs(to, s, t, g, tin, up, ans);
				up[s] = min(up[s], up[to]);
				if (up[to] > up[s]) ans.push_back({ s, to });
			}
			else up[s] = min(up[s], tin[to]);
		}
	}
public:
	Bridges() { }
	vector<pair<int, int>> find(vector<vector<int>> &g) {
		int n = g.size();
		vector<int> tin(n), up(n);
		vector<pair<int, int>> ans;
		int t = 1;
		for (int i = 0; i < n; i++) {
			if (tin[i] == 0) dfs(i, -1, t, g, tin, up, ans);
		}
		return ans;
	} 
	vector<pair<int, int>> operator ()(vector<vector<int>> &g) {
		return find(g);
	}
};

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
	Bridges br;
	vector<pair<int, int>> ans = br(g);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
	}
}
