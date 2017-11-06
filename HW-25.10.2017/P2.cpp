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
			euler(e.to, first, ans, directed);
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
		euler(s, first, ans, directed);
		return ans;
	}
	void clear() { graph.clear(); }
	vector<Edge>& operator [] (int pos) { return graph[pos]; }
};

int main() {
	int n, k;
	cin >> n >> k;
	n--;
	vector<int> pows(n + 1);
	pows[0] = 1;
	for (int i = 1; i <= n; i++)
		pows[i] = pows[i - 1] * k;
	Euler e(pows[n]);
	for (int i = 0; i < e.size(); i++) {
		// 00...00
		// 00...01
		// 00...0k
		// 00...10
		// .......
		// kk...kk
		int cur = i / k;
		for (int j = 0; j < k; j++) {
			e.insert(i, cur, true);
			cur += pows[n - 1];
		}
	}
	vector<int> a = e.find(true);
	for (int i = 0; i < a.size() - 1; i++)
		cout << a[i] % k << " ";
}
