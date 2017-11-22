#include <bits/stdc++.h>
using namespace std;

class Matching {
	bool dfs(int s, vector<vector<int>> &g, vector<bool> &was, vector<int> &match) {
		was[s] = true;
		for (int to : g[s]) {
			if (match[to] == -1 || (!was[match[to]] && dfs(match[to], g, was, match))) {
				match[to] = s;
				match[s] = to;
				return true;
			}
		}
		return false;
	}
	
public:
	Matching() { }
	vector<int> kuhn(vector<vector<int>> &g) {
		int n = g.size();
		vector<int> match(n, -1);
		vector<bool> was(n);
		for (int i = 0; i < n; i++) {
			if (was[i]) continue;
			if (dfs(i, g, was, match)) {
				fill(was.begin(), was.end(), false);
			}
			
		}
		return match;
	} 
	vector<int> operator ()(vector<vector<int>> &g, int k = -1) {
		return get(g, k);
	}
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	Matching mat;
	vector<int> match = mat(g, k);
	vector<pair<int, int>> edg;
	for (int i = 0; i < n; i++) {
		if (i < match[i]) edg.push_back({ i, match[i] });
	}
	for (int i = 0; i < edg.size(); i++) {
		cout << edg[i].first + 1 << " " << edg[i].second + 1 << "\n";
	}
}
