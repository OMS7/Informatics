#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long double db;
int shortest_path(int n, int m, vector<pii> &squares) {
	vector<vector<db>> path(n + 1, vector<db>(m + 1));
	vector<vector<bool>> iss(n + 1, vector<bool>(m + 1));
	for (int i = 0; i < squares.size(); i++) {
		iss[squares[i].first][squares[i].second] = 1;
	}
	path[0][0] = 0;
	for (int i = 1; i < n + 1; i++) {
		path[i][0] = path[i - 1][0] + 100;
	}
	for (int i = 1; i < m + 1; i++) {
		path[0][i] = path[0][i - 1] + 100;
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (iss[i][j]) path[i][j] = path[i - 1][j - 1] + 100 * sqrt(2);
			else path[i][j] = min(path[i - 1][j], path[i][j - 1]) + 100;
		}
	}
	return round(path[n][m]);
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<pii> squares(k);
	for (int i = 0; i < k; i++) {
		cin >> squares[i].first >> squares[i].second;
	}
	cout << shortest_path(n, m, squares);
}
