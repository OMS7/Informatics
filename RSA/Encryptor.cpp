#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int bpow(int a, int b, int m) {
	int res = 1;
	while (b) {
		if (b % 2) res = (1ll * res * a) % m;
		a = (1ll * a * a) % m;
		b /= 2;
	}
	return res;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int e, n;
	cin >> e >> n;
	string s;
	cin >> s;
	string ans;
	for (int i = 0; i < s.size(); i++) {
		int q = s[i];
		q = bpow(q, e, n);
		cout << q << " ";
	}
}
