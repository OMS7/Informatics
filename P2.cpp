#include <iostream>
using namespace std;
// Бинарное возведение числа "а" в степень "b" 
double binpow(double a, int b) {
	if (b == 0) return 1;
	if (b < 0) return 1 / binpow(a, -b);
	double r = 1;
	while (b) {
		if (b & 1) r *= a;
		a *= a;
		b >>= 1;
	}
	return r;
}
int main() {
	double a;
	int b;
	cin >> a >> b;
	cout << binpow(a, b) << endl;
	return 0;
}
