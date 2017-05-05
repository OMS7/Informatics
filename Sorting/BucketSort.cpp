#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
void bucketsort(vector<int> &a, int nb) {
	if (a.size() <= 1) return;
	int minz = a[0], maxz = a[0];
	for (int i = 1; i < a.size(); i++) {
		minz = min(minz, a[i]);
		maxz = max(maxz, a[i]);
	}
	int range = maxz - minz;
	if (range == 0) return;
	vector<vector<int>> buckets(nb);
	int q = (range + nb - 1) / nb;
	for (int i = 0; i < a.size(); i++) {
		int ind = (int)(a[i] - minz) / q;
		buckets[min(nb - 1, ind)].push_back(a[i]);
	}
	for (int i = 0; i < nb; i++) bucketsort(buckets[i], nb);
	int cur = 0;
	for (int i = 0; i < nb; i++)
		for (int j = 0; j < buckets[i].size(); j++)
			a[cur++] = buckets[i][j];
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
		bucketsort(v, 35);
		int c2 = clock();
		assert(check(q, v));
		printf("%d\n", c2 - c1);
		fclose(stdin);
	}
}
