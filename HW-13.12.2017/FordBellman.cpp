#include <bits/stdc++.h>
using namespace std;

template <class T>
class FordBellman {
public:
	T inf;
	FordBellman(T _inf) { inf = _inf; }
	vector<T> find(int s, vector<vector<pair<int, T>>> &g) {
		int n = g.size();
		vector<T> dist(n, inf);
		dist[s] = 0;
		bool run = true;
		while (run) {
			run = false;
			for (int i = 0; i < n; i++) {
				for (auto t : g[i]) {
					int to = t.first;
					T d = t.second;
					if (dist[to] > dist[i] + d) {
						dist[to] = dist[i] + d;
						run = true;
					}
				}
			}
		}
		return dist;
	}
	vector<T> operator ()(int s, vector<vector<pair<int, T>>> &g) {
		return find(s, g);
	}
};

int main() {
	int n, m, s;
	cin >> n >> m >> s;
	s--;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].push_back({ b, c });
		g[b].push_back({ a, c });
	}
	FordBellman<int> fb((int)1e9);
	vector<int> dist = fb(s, g);
	for (int i = 0; i < n; i++) {
		if (dist[i] == (int)1e9) cout << "-1 ";
		else cout << dist[i] << " ";
	}
}
