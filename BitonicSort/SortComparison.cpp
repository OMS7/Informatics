#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std; 
int kbs = 0, kqs = 0, kms = 0;
template <typename T> class heap {
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
void bitseqsort(vector<int> &a, int l, int r, bool b) {
	if (l == r - 1) return;
	int m = (l + r) / 2;
	for (int i = l, j = m; j < r; i++, j++) {
		kbs++;
		if (b ^ (a[i] > a[j])) swap(a[i], a[j]);
	}
	bitseqsort(a, l, m, b);
	bitseqsort(a, m, r, b);
}
void makebitonic(vector<int> &a, int l, int r) {
	if (r - l <= 1) return;
	int m = (l + r) / 2;
	makebitonic(a, l, m);
	bitseqsort(a, l, m, 0);
	makebitonic(a, m, r);
	bitseqsort(a, m, r, 1);
}
void bitsort(vector<int> &a) {
	int n = 1;
	while (n < a.size()) n *= 2;
	a.resize(n, 2e9);
	makebitonic(a, 0, n);
	bitseqsort(a, 0, n, 0);
	while (a.back() == 2e9 && !a.empty()) a.pop_back();
}
void QuickSort(vector<int> &v, int l, int r) {
	int z = v[(l + r) / 2];
	int ll = l, rr = r;
	while (ll <= rr) {
		while (v[ll] < z) ll++, kqs++;
		while (v[rr] > z) rr--, kqs++;
		if (ll <= rr) swap(v[ll++], v[rr--]);
	}
	if (l < rr) QuickSort(v, l, rr);
	if (ll < r) QuickSort(v, ll, r);
}
void merge(vector<int> &v, int l, int r) {
	int m = (l + r) / 2;
	int cl = l, cr = m, cur = 0;
	vector<int> ans(r - l);
	while (cl < m && cr < r) {
		kms++;
		if (v[cl] < v[cr]) ans[cur++] = v[cl++];
		else ans[cur++] = v[cr++];
	}
	while (cl < m) ans[cur++] = v[cl++];
	while (cr < r) ans[cur++] = v[cr++];
	for (int i = 0; i < r - l; i++)
		v[i + l] = ans[i];
}
void mergesort(vector<int> &v, int l, int r) {
	if (l >= r - 1) return;
	int m = (l + r) / 2;
	mergesort(v, l, m);
	mergesort(v, m, r);
	merge(v, l, r);
}
//----------------------------------
void generate(int n) {
	vector<int> v(n);
	for (int i = 0; i < n; i++) v[i] = rand();
	for (int i = 0; i < n; i++) printf("%d ", v[i]);
}
void solvebitonic(int n) {
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int c1 = clock();
	bitsort(a);
	int c2 = clock();
	printf("%d %d\n", c2 - c1, kbs);
	kbs = 0;
}
void solvesort(int n) {
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int c1 = clock();
	sort(a.begin(), a.end());
	int c2 = clock();
	printf("%d\n", c2 - c1);
}
void solvequick(int n) {
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int c1 = clock();
	QuickSort(a, 0, n - 1);
	int c2 = clock();
	printf("%d %d\n", c2 - c1, kqs);
	kqs = 0;
}
void solvemerge(int n) {
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int c1 = clock();
	mergesort(a, 0, n);
	int c2 = clock();
	printf("%d %d\n", c2 - c1, kms);
	kms = 0;
}
void solveset(int n) {
	multiset<int> s;
	int c = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		int c1 = clock();
		s.insert(a);
		int c2 = clock();
		c += c2 - c1;
	}
	printf("%d\n", c);
}
void solveheap(int n) {
	heap<int> h;
	int c = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		int c1 = clock();
		h.push(a);
		int c2 = clock();
		c += c2 - c1;
	}
	vector<int> ans(n);
	int cur = 0, c1 = clock();
	while (cur != n) {
		ans[cur++] = h.top();
		h.pop();
	}
	int c2 = clock();
	c += c2 - c1;
	printf("%d\n", c);
}
int main() {
	srand(time(0));
	const int N = 1e5;
	for (int i = 0; i < 10; i++) {
		freopen("a.in", "w", stdout);
		generate(N);
		fclose(stdout);
		freopen("a.in", "r", stdin);
		freopen("a.out", "a", stdout);
		solveheap(N);
		fclose(stdin);
		fclose(stdout);
	}
}
