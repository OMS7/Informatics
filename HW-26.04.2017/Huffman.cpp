#include <bits/stdc++.h>
using namespace std;
struct S {
	string s;
	int a;
	bool operator < (const S &b) const {
		return a < b.a;
	}
};
int main() {
	int n;
	cin >> n;
	multiset<S> ss;
	map<char, int> m;
	vector<char> vc(n);
	for (int i = 0; i < n; i++) {
		char c;
		int a;
		cin >> c >> a;
		m[c] = i;
		string s;
		s.push_back(c);
		ss.insert({ s, a });
		vc[i] = c;
	}
	vector<vector<bool>> ans(n);
	while (ss.size() != 1) {
		S s1 = *ss.begin();
		ss.erase(ss.begin());
		S s2 = *ss.begin();
		ss.erase(ss.begin());
		for (int i = 0; i < s1.s.size(); i++) ans[m[s1.s[i]]].push_back(0);
		for (int i = 0; i < s2.s.size(); i++) ans[m[s2.s[i]]].push_back(1);
		if (s1.s.size() < s2.s.size()) swap(s1, s2);
		string q = s1.s + s2.s;
		int a = s1.a + s2.a;
		ss.insert({ q, a });
	}
	for (int i = 0; i < n; i++) {
		cout << vc[i] << " : ";
		reverse(ans[i].begin(), ans[i].end());
		for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j];
		cout << endl;
	}
}
