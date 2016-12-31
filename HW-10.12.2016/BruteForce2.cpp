#include <bits/stdc++.h>
using namespace std;
int v[12];
void FifthFunc() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			v[4] = i; v[6] = j;
			for (int q = 0; q < 12; q++) {
				cout << v[q];
			}
			cout << '\n';
		}
	}
}
void FourthFunc() {
	for (int i = 0; i < 10; i++) {
		v[0] = i;
		if ((v[0] + v[1] + v[2]) % 2 == 0) {
			FifthFunc();
		}
	}
}
void ThirdFunc() {
	for (int i = 0; i < 10; i++) {
		v[10] = i;
		if ((v[9] + v[10] + v[11]) % 3 == 0) {
			FourthFunc();
		}
	}
}
void SecondFunc(int pos, int s) {
	if (pos >= 12) {
		if (s % 11 != 0) return;
		ThirdFunc();
		return;
	}
	if (v[pos] != -1) {
		SecondFunc(pos + 3, s + v[pos]);
		return;
	}
	for (int i = 0; i < 10; i++) {
		v[pos] = i;
		SecondFunc(pos + 3, s + v[pos]);
	}
}
void FirstFunc(int pos, int r) {
	if (pos >= 12) {
		if (r) return;
		SecondFunc(2, 0);
		return;
	}
	for (int i = 0; i <= min(r, 9); i++) {
		v[pos] = i;
		FirstFunc(pos + 2, r - i);
	}
}
int main() {
	for (int i = 0; i < 12; i++) v[i] = -1;
	FirstFunc(1, 21);
}
