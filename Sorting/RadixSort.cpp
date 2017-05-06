#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
const int N = 8;
const int M = 1 << N;
int digit(int n, int k) {
	return (n >> (N * k) & (M - 1));
}
void radixsort(vector<int> &a) {
	int k = (32 + N - 1) / N;
	int n = a.size();
	vector<int> b(n);
	for (int i = 0; i < k; i++) {
		vector<int> c(M);
		for (int j = 0; j < n; j++)
			c[digit(a[j], i)]++;
		for (int j = 1; j < M; j++)
			c[j] += c[j - 1];
		for (int j = n - 1; j >= 0; j--)
			b[--c[digit(a[j], i)]] = a[j];
		for (int j = 0; j < n; j++)
			a[j] = b[j];
	}
}
template <class T> 
bool check(vector<T> &a, vector<T> &b) {
	sort(a.begin(), a.end());
	return a == b;
}
int main() {
	freopen("time.txt", "w", stdout);
	for (int i = 1; i <= 203; i++) {
		string s = "Tests//test" + to_string(i) + ".txt";
		freopen(s.c_str(), "r", stdin);
		int n;
		cin >> n;
		vector<int> v(n);
		for (int j = 0; j < n; j++) scanf("%d", &v[j]);
		vector<int> q = v;
		int c1 = clock();
		radixsort(v);
		int c2 = clock();
		assert(check(q, v));
		printf("%d\n", c2 - c1);
		fclose(stdin);
	}
}
