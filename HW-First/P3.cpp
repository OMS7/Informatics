#include <iostream>
#include <vector>
using namespace std;
// Вывод всех простых чисел от 1 до n
int main() {
	int n;
	cin >> n;
	vector<bool> pr(n + 1, 1);
	vector<int> res;
	pr[0] = pr[1] = 0;
	for (int i = 2; i < n; i++) {
		if (!pr[i]) continue;
		for (int j = i * i; j <= n; j += i) {
			pr[j] = 0;
		}
		res.push_back(i);
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}