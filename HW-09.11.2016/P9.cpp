#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
int StrangeSum(vi v, int l, int r) {
	if (l == r - 1) return v[l];
	else return StrangeSum(v, l, (l + r) / 2)
		+ StrangeSum(v, (l + r) / 2, r);
}
int main() {
	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	cout << StrangeSum(v, 0, n);
}