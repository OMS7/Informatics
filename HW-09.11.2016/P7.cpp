#include <iostream>
using namespace std;
typedef long long ll;
ll StrangeMultiply(int a, int b) {
	if (a > b) swap(a, b);
	ll res = 0;
	for (ll i = 0; i < a; i++) {
		res += b;
	}
	return res;
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << StrangeMultiply(a, b);
	return 0;
}