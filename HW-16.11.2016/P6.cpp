#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi BuildSnake(int n, int m) {
	vvi snake(n, vi(m, -1));
	int dir = 0, k = n*m, cx = m - 1, cy = 0;
	while (cy < n && cx < m && snake[cy][cx] == -1) {
		snake[cy][cx] = k;
		if (dir == 0) {
			if (cx == 0 || snake[cy][cx - 1] != -1) {
				dir = 1;
				cy++;
			}
			else cx--;
		}
		else if (dir == 1) {
			if (cy + 1 == n || snake[cy + 1][cx] != -1) {
				dir = 2;
				cx++;
			}
			else cy++;
		}
		else if (dir == 2) {
			if (cx + 1 == m || snake[cy][cx + 1] != -1) {
				dir = 3;
				cy--;
			}
			else cx++;
		}
		else {
			if (cy == 0 || snake[cy - 1][cx] != -1) {
				dir = 0;
				cx--;
			}
			else cy--;
		}
		k--;
	}
	return snake;
}
int main() {
	int n, m;
	cin >> n >> m;
	vvi snake = BuildSnake(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << snake[i][j] << '\t';
		}
		cout << endl;
	}
}