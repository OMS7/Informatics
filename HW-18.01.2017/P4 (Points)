#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int outer_points(vector<pii> &segments, int point) {
	int ret = 0;
	for (int i = 0; i < segments.size(); i++) {
		if (point < segments[i].first || point > segments[i].second) ret++;
	}
	return ret;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<pii> segments(n);
	for (int i = 0; i < n; i++) {
		cin >> segments[i].first >> segments[i].second;
	}
	for (int i = 0; i < m; i++) {
		int p; cin >> p;
		cout << outer_points(segments, p) << ' ';
	}
}
