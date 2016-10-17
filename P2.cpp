#include <iostream>
using namespace std;
// Бинарное возведение числа "а" в степень "b" 
int binpow(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r *= a;
		a *= a;
		b >>= 1;
	}
	return r;
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << binpow(a, b) << endl;
	return 0;
}
