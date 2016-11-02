#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef vector<int> vi;
vi DeleteDuplicates(vi v) {
	set<int> si;
	vi res;
	int n = v.size();
	for (int i = 0; i < n; i++) {
		int q1 = si.size();
		si.insert(v[i]);
		if (si.size() > q1) res.push_back(v[i]);
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
	vi res = DeleteDuplicates(v);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	return 0;
}