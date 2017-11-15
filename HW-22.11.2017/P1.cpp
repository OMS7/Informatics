#include <bits/stdc++.h>
using namespace std;

class CutVertex {
	void dfs(int s, int p, int &t, vector<vector<int>> &g, vector<int> &tin,
		vector<int> &up, vector<int> &ans) {
		tin[s] = up[s] = t++;
		int v = 0;
		for (int to : g[s]) {
			if (p == to) continue;
			if (!tin[to]) {
				v++;
				dfs(to, s, t, g, tin, up, ans);
				up[s] = min(up[s], up[to]);
			}
			else up[s] = min(up[s], tin[to]);
		}
		if (p != -1) {
			for (int to : g[s]) {
				if (up[to] >= tin[s]) {
					ans.push_back(s);
					break;
				}
			}
		}
		if (p == -1 && v > 1) ans.push_back(s);
	}
public:
	CutVertex() { }
	vector<int> find(vector<vector<int>> &g) {
		int n = g.size();
		vector<int> tin(n), up(n), ans;
		int t = 1;
		for (int i = 0; i < n; i++) {
			if (tin[i] == 0) dfs(i, -1, t, g, tin, up, ans);
		}
		return ans;
	} 
	vector<int> operator ()(vector<vector<int>> &g) {
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
	CutVertex cv;
	vector<int> ans = cv(g);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << " ";
	}
}
