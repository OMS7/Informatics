#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi DigTrench(int n) {
	vvi trench(n, vi(n, -1));
	int dir = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			trench[i][j] = abs(i - j);
		}
	}
	return trench;
}
int main() {
	int n;
	cin >> n;
	vvi trench = DigTrench(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << trench[i][j] << ' ';
		}
		cout << endl;
	}
}