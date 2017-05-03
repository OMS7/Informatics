#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
template <class T>
class heap {
public:
	int size() {
		return n;
	}
	int top() {
		return h[0];
	}
	bool empty() {
		return n == 0;
	}
	void push(T a) {
		h.push_back(a);
		SiftUp(n);
		n++;
	}
	void merge(const heap &q) {
		for (int i = 0; i < q.size(); i++) push(q[i]);
	}
	void pop() {
		n--;
		swap(h[n], h[0]);
		h.pop_back();
		SiftDown(0);
	}
	void clear() {
		h.clear();
		n = 0;
	}
	T operator [] (int a) {
		return h[a];
	}
private:
	vector<T> h;
	int n = 0;
	void SiftUp(int a) {
		while (a) {
			int p = (a - 1) / 2;
			if (h[p] > h[a]) swap(h[p], h[a]);
			else break;
			a--; a /= 2;
		}
	}
	void SiftDown(int a) {
		while (2 * a + 1 < n) {
			int l = 2 * a + 1, r = 2 * a + 2;
			if (r == n) {
				if (h[l] < h[a]) swap(h[l], h[a]);
				break;
			}
			else if (h[l] <= h[r]) {
				if (h[l] < h[a]) {
					swap(h[l], h[a]);
					a = l;
				}
				else break;
			}
			else if (h[r] < h[a]) {
				swap(h[r], h[a]);
				a = r;
			}
			else break;
		}
	}
};
template <class T>
void heapsort(vector<T> &a, int l, int r) {
	heap<T> h;
	for (int i = l; i < r; i++) h.push(a[i]);
	int cur = l;
	while (cur < r) {
		a[cur++] = h.top();
		h.pop();
	}
}
template <class T> 
void _quicksort(vector<T> &v, int l, int r, int depth) {
	if (depth == 0) {
		heapsort(v, l, r + 1);
		return;
	}
	int z = v[(l + r) / 2];
	int ll = l, rr = r;
	while (ll <= rr) {
		while (v[ll] < z) ll++;
		while (v[rr] > z) rr--;
		if (ll <= rr) swap(v[ll++], v[rr--]);
	}
	if (l < rr) _quicksort(v, l, rr, depth - 1);
	if (ll < r) _quicksort(v, ll, r, depth - 1);
}
template <class T>
void introsort(vector<T> &a) {
	int n = a.size();
	int md = 2 * log2(n);
	_quicksort(a, 0, n - 1, md);
}
template <class T>
bool check(vector<T> &init, vector<T> &ans) {
	sort(init.begin(), init.end());
	return init == ans;
}
int main() {
	freopen("time.txt", "w", stdout);
	for (int i = 1; i <= 203; i++) {
		string s = "Tests//test" + to_string(i) + ".txt";
		freopen(s.c_str(), "r", stdin);
		int n;
		cin >> n;
		vector<int> v(n);
		for (int j = 0; j < n; j++) scanf("%d", &v[j]);
		vector<int> q = v;
		int c1 = clock();
		introsort(v);
		int c2 = clock();
		assert(check(q, v));
		printf("%d\n", c2 - c1);
		fclose(stdin);
	}
}
