#include <iostream>
#include <vector>
using namespace std;
int MaxCube(int n) {
	int l = 1, r = n + 1;
	while (l < r - 1) {
		int m = (l + r) / 2;
		if (m*m*m > n) r = m;
		else l = m;
	}
	return l;
}
int main() {
	int n;
	cin >> n;
	vector<int> res;
	while (n) {
		int c = MaxCube(n);
		n -= c*c*c;
		res.push_back(c);
	}
	if (res.size() > 8) cout << "Impossible";
	else {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
		}
	}
}