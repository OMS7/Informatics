#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
int main() {
	srand(time(0));
	freopen("keys.txt", "w", stdout);
	const int N = 1e4 + 10;
	vector<int> primes;
	vector<bool> is_prime(N, 1);
	for (int i = 2; i < N; i++) {
		if (!is_prime[i]) continue;
		if (i > 1e3) primes.push_back(i);
		if (1ll * i * i > N) continue;
		for (int j = i * i; j < N; j += i) {
			is_prime[j] = 0;
		}
	}
	random_shuffle(primes.begin(), primes.end());
	int p = primes[0];
	int q = primes[1];
	int n = p * q;
	int e = primes[2];
	int x, y;
	int g = gcd(e, n, x, y);
	x = (x % n + n) % n;
	int d = x;
	cout << "public key: " << e << " " << n << endl;
	cout << "private key: " << d << " " << n << endl;
}
