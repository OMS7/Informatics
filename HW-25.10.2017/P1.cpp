#include <bits/stdc++.h>
using namespace std;

class Euler {
	struct Edge {
		int to, rev;
		bool vis;
		Edge(int _to, int _rev, bool _vis) { to = _to; rev = _rev; vis = _vis; }
	};
	vector<vector<Edge>> graph;
	void euler(int s, vector<int> &first, vector<int> &ans, bool directed = false) {
		while (first[s] < graph[s].size()) {
			Edge &e = graph[s][first[s]++];
			if (e.vis) continue;
			e.vis = true;
			if (!directed) graph[e.to][e.rev].vis = true;
			euler(e.to, first, ans);
		}
		ans.push_back(s);
	}

public:
	Euler() { }
	Euler(int n) { graph.resize(n); }
	template <class G> Euler(G& _graph) { build(_graph); }
	int size() { return (int)graph.size(); }
	void insert(int a, int b, bool directed = false) {
		graph[a].push_back(Edge(b, (int)graph[b].size(), false));
		if (!directed) graph[b].push_back(Edge(a, (int)graph[a].size() - 1, false));
	}
	template <class G> void build(G& _graph) {
		int n = _graph.size();
		graph.resize(n);
		for (int i = 0; i < n; i++)
			graph.clear();
		for (int i = 0; i < n; i++) {
			for (int j : _graph[i]) {
				if (i <= j) insert(i, j);
			}
		}
	}
	bool checkc(bool directed = false) {
		if (directed) {
			vector<int> deg1(size()), deg2(size());
			for (int i = 0; i < size(); i++) {
				deg1[i] = graph[i].size();
				for (auto a : graph[i]) {
					deg2[a.to]++;
				}
			}
			for (int i = 0; i < size(); i++) {
				if (deg1[i] != deg2[i]) return false;
			}
		}
		else {
			for (int i = 0; i < size(); i++) {
				if (graph[i].size() % 2) return false;
			}
		}
	}
	vector<int> find(bool directed = false) {
		int s = 0;
		if (directed) {
			vector<int> deg1(size()), deg2(size());
			for (int i = 0; i < size(); i++) {
				deg1[i] = graph[i].size();
				for (auto a : graph[i]) {
					deg2[a.to]++;
				}
			}
			for (int i = 0; i < size(); i++) {
				if (deg1[i] < deg2[i]) s = i;
			}
		}
		else {
			for (int i = 0; i < size(); i++) {
				if (graph[i].size() % 2) s = i;
			}
		}
		vector<int> ans, first(size());
		euler(s, first, ans);
		return ans;
	}
	void clear() { graph.clear(); }
	vector<Edge>& operator [] (int pos) { return graph[pos]; }
};

int main() {
	int n, m;
	cin >> n >> m;
	Euler e(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		e.insert(a, b);
	}
	if (!e.checkc()) {
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	vector<int> ans = e.find();
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] + 1 << " ";
}
