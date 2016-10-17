#include <iostream>
using namespace std;
// Вычисление функции Эйлера числа "n"
int EulerFunc(int n) {
	int ph = 1, k;
	for (int i = 2; i*i <= n; i++) {
		k = 1;
		while (n % i == 0) {
			n /= i;
			k *= i;
		}
		ph *= k - k / i;
	}
	if (n > 1) ph *= n - 1;
	return ph;
}
int main() {
	int n;
	cin >> n;
	cout << EulerFunc(n) << endl;
	return 0;
}
