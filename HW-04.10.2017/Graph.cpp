#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v1(n, vector<int>(n));
	vector<vector<int>> v2(n);
	vector<vector<int>> v3(n, vector<int>(m));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		v1[a][b] = v1[b][a] = 1;
		v2[a].push_back(b);
		v2[b].push_back(a);
		v3[a][i] = v3[b][i] = 1;
	}
	cout << "Матрица смежности:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v1[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "Список смежности:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v2[i].size(); j++) {
			cout << v2[i][j] + 1 << " ";
		}
		cout << "\n";
	}
	cout << "Матрица инцидентности:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v3[i][j] << " ";
		}
		cout << "\n";
	}
}
