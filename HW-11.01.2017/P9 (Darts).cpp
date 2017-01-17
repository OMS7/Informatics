#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<string> ans;
void output() {
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}
void darts_game(int n, int pos) {
	if (n < 0) return;
	if (n == 0) {
		if (ans.back()[0] == 'D' || ans.back() == "Bull") output();
		return;
	}
	if (pos == 3) {
		if (n % 2 == 0) {
			ans.push_back("D" + to_string(n / 2));
			output();
			ans.pop_back();
		}
		return;
	}
	for (int i = 1; i <= 20; i++) {
		ans.push_back(to_string(i));
		darts_game(n - i, pos + 1);
		ans.pop_back();
		ans.push_back("D" + to_string(i));
		darts_game(n - 2 * i, pos + 1);
		ans.pop_back();
		ans.push_back("T" + to_string(i));
		darts_game(n - 3 * i, pos + 1);
		ans.pop_back();
	}
	ans.push_back(to_string(25));
	darts_game(n - 25, pos + 1);
	ans.pop_back();
	ans.push_back("Bull");
	darts_game(n - 50, pos + 1);
	ans.pop_back();
}
int main() {
	int n;
	cin >> n;
	darts_game(n, 1);
}
