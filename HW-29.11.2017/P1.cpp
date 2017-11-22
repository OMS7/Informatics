#include <bits/stdc++.h>
using namespace std;

class Bipart {
	bool dfs(int s, vector<vector<int>> &g, vector<int> &col) {
		for (int to : g[s]) {
			if (col[to] == -col[s]) continue;
			if (col[to] == 0) {
				col[to] = -col[s];
				if (!dfs(to, g, col)) return false;
			}
		}
		return true;
	}
	
public:
	Bipart() { }
	vector<int> get(vector<vector<int>> &g) {
		int n = g.size();
		vector<int> col(n);
		for (int i = 0; i < n; i++) {
			if (col[i] == 0) {
				col[i] = 1;
				if (!dfs(i, g, col)) return vector<int>{ -1 };
			}
		}
		return col;
	} 
	vector<int> operator ()(vector<vector<int>> &g) {
		return get(g);
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
	Bipart bp;
	vector<int> col = bp(g);
	if (col.size() == 1 && n != 1) {
		cout << -1;
		return 0;
	}
	cout << col.size() << endl;
	for (int i = 0; i < col.size(); i++) {
		if (col[i] == -1) cout << 2 << " ";
		else cout << 1 << " ";
	}
}
