#include <bits/stdc++.h>
using namespace std;
string num;
int n;
void f(int pos, int sum) {
	if (pos >= (n + 1) / 2) {
		if (sum % 9 == 0) cout << num << endl;
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (i == 0 && pos == 0) continue;
		num[pos] = num[n - pos - 1] = i + '0';
		if (n % 2 && pos == n / 2) sum += i;
		else sum += 2 * i;
		if (pos < (n + 1) / 2) f(pos + 1, sum);
		if (n % 2 && pos == n / 2) sum -= i;
		else sum -= 2 * i;
	}
}
int main() {
	cin >> n;
	num.resize(n);
	f(0, 0);
}
