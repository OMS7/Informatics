#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void bfs(int s, vector<vector<int>> &g, vector<int> &d, vector<int> &p) {
	fill(d.begin(), d.end(), inf);
	queue<int> q;
	q.push(s);
	d[s] = 0;
	p[s] = -1;
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (int to : g[f]) {
			if (d[to] == inf) {
				d[to] = d[f] + 1;
				p[to] = f;
				q.push(to);
			}
		}
	}
}
int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	a--; b--;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int s, t;
		cin >> s >> t;
		s--; t--;
		g[s].push_back(t);
		g[t].push_back(s);
	}
	vector<int> d(n), p(n);
	bfs(b, g, d, p);
	int ans = d[a];
	if (ans == inf) {
		cout << -1;
		return 0;
	}
	cout << ans << endl;
	while (b != a) {
		cout << a + 1 << " ";
		a = p[a];
	}
	cout << b + 1;
}
