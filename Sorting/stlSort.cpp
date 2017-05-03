#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
template <class T>
bool check(vector<T> &init, vector<T> &ans) {
	sort(init.begin(), init.end());
	return init == ans;
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
		int c1 = clock();
		sort(v.begin(), v.end());
		int c2 = clock();
		printf("%d\n", c2 - c1);
		fclose(stdin);
	}
}
