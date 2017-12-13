#include <bits/stdc++.h>
using namespace std;

template <class T>
class Dijkstra {
public:
	T inf;
	Dijkstra(T _inf) { inf = _inf; }
	vector<T> find(int s, vector<vector<pair<int, T>>> &g) {
		int n = g.size();
		vector<T> dist(n, inf);
		dist[s] = 0;
		set<pair<T, int>> se;
		se.insert({ 0, s });
		while (!se.empty()) {
			auto p = *se.begin();
			int f = p.second;
			se.erase(se.begin());
			for (auto t : g[f]) {
				int to = t.first;
				T d = t.second;
				if (dist[f] + d < dist[to]) {
					se.erase({ dist[to], to });
					dist[to] = dist[f] + d;
					se.insert({ dist[to], to });
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
	Dijkstra<int> dijk((int)1e9);
	vector<int> dist = dijk(s, g);
	for (int i = 0; i < n; i++) {
		if (dist[i] == (int)1e9) cout << "-1 ";
		else cout << dist[i] << " ";
	}
}
