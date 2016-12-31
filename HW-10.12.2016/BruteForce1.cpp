#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, a;
	cin >> n;
	int ans = 1;
	for (int i = 0; i < n; i++) {
		cin >> a;
		int k = 0, q = a;
		for (int d = 2; d <= sqrt(q); d++) {
			if (q % d == 0) k++;
			while (q % d == 0) q /= d;
		}
		if (q != a) k++;
		if (k != 0 && k <= 2) ans *= a;
	}
	cout << ans;
}
