#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi BuildZigg(int n) {
	vvi zigg(n, vi(n, -1));
	int dir = 0;
	for (int i = 0; i < n; i++) {
		if (zigg[i][i] != -1) break;
		dir = 0;
		int cx = i, cy = i;
		while (zigg[cy][cx] == -1) {
			zigg[cy][cx] = i + 1;
			if (dir == 0) {
				if (cx + 1 == n || zigg[cy][cx + 1] != -1) {
					dir = 1;
					cy++;
				}
				else cx++;
			}
			else if (dir == 1) {
				if (cy + 1 == n || zigg[cy + 1][cx] != -1) {
					dir = 2;
					cx--;
				}
				else cy++;
			}
			else if (dir == 2) {
				if (cx == 0 || zigg[cy][cx - 1] != -1) {
					dir = 3;
					cy--;
				}
				else cx--;
			}
			else {
				if (cy - 1 == i) dir = 4;
				else cy--;
			}
		}
	}
	return zigg;
}
int main() {
	int n;
	cin >> n;
	vvi zigg = BuildZigg(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << zigg[i][j] << ' ';
		}
		cout << endl;
	}
}