#include <bits/stdc++.h>
using namespace std;
string num;
void print_palindrome(int pos, int sum, int n) {
	if (pos >= (n + 1) / 2) {
		if (sum % 9 == 0) cout << num << endl;
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (i == 0 && pos == 0) continue;
		num[pos] = num[n - pos - 1] = i + '0';
		if (pos == n - pos - 1) sum += i;
		else sum += 2 * i;
		print_palindrome(pos + 1, sum, n);
		if (pos == n - pos - 1) sum -= i;
		else sum -= 2 * i;
	}
}
int main() {
	int n;
	cin >> n;
	num.resize(n);
	print_palindrome(0, 0, n);
}
