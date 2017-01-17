#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int migraine_minimization(int n) {
	vector<int> dp(n + 1, 1e9);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int s = sqrt(i);
		for (int q = 1; q <= s; q++) {
			dp[i] = min(dp[i], dp[i - q*q] + 1);
		}
	}
	return dp.back() * 4;
}
int main() {
	int n;
	cin >> n;
	cout << migraine_minimization(n);
}
