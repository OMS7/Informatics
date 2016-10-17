#include <iostream>
using namespace std;
// Вычисление НОК чисел "a" и "b"
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << a * b / gcd(a, b) << endl;
	return 0;
}
