#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
typedef vector<int> vi;
vi DeleteAnnoyingPrimes(vi v) {
	vi res;
	map<int, int> m;
	int n = v.size();
	for (int i = 0; i < n; i++) {
		int a = v[i];
		bool b = 1;
		for (int j = 2; j <= sqrt(a); j++) {
			if (a%j == 0) {
				b = 0; break;
			}
		}
		if (b) m[a]++;
		else res.push_back(a);
	}
	for (auto i : m) {
		if (i.second == 1) res.push_back(i.first);
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vi res = DeleteAnnoyingPrimes(v);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
}