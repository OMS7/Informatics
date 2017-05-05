#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int rrand() {
	return (rand() << 15) + rand();
}
int main() {
	srand(time(0));
	int N[7] = { 1e4, 5e4, 1e5, 5e5, 1e6, 5e6, 1e7 };
	int cnt = 1;
	// 1 - 7: sorted diff
	for (int i = 0; i < 7; i++) {
		string s = "test" + to_string(cnt) + ".txt";
		freopen(s.c_str(), "w", stdout);
		printf("%d\n", N[i]);
		for (int j = 0; j < N[i]; j++) {
			printf("%d ", j + 1);
		}
		fclose(stdout);
		cnt++;
	}
	// 8 - 14: sorted reverse diff
	for (int i = 0; i < 7; i++) {
		string s = "test" + to_string(cnt) + ".txt";
		freopen(s.c_str(), "w", stdout);
		printf("%d\n", N[i]);
		for (int j = 0; j < N[i]; j++) {
			printf("%d ", N[i] - j);
		}
		fclose(stdout);
		cnt++;
	}
	// 15 - 21: one element
	for (int i = 0; i < 7; i++) {
		string s = "test" + to_string(cnt) + ".txt";
		freopen(s.c_str(), "w", stdout);
		printf("%d\n", N[i]);
		for (int j = 0; j < N[i]; j++) {
			printf("1 ");
		}
		fclose(stdout);
		cnt++;
	}
	// 22 - 28: mountains
	for (int i = 0; i < 7; i++) {
		string s = "test" + to_string(cnt) + ".txt";
		freopen(s.c_str(), "w", stdout);
		printf("%d\n", N[i]);
		for (int j = 0; j < N[i] / 2; j++) {
			printf("1 2 ");
		}
		fclose(stdout);
		cnt++;
	}
	// 29 - 63: random, elem < 100, 5 tests
	for (int i = 0; i < 7; i++) {
		for (int t = 0; t < 5; t++) {
			string s = "test" + to_string(cnt) + ".txt";
			freopen(s.c_str(), "w", stdout);
			printf("%d\n", N[i]);
			for (int j = 0; j < N[i]; j++) {
				printf("%d ", rrand() % 100);
			}
			fclose(stdout);
			cnt++;
		}
	}
	// 64 - 98: random, elem < 10000, 5 tests
	for (int i = 0; i < 7; i++) {
		for (int t = 0; t < 5; t++) {
			string s = "test" + to_string(cnt) + ".txt";
			freopen(s.c_str(), "w", stdout);
			printf("%d\n", N[i]);
			for (int j = 0; j < N[i]; j++) {
				printf("%d ", rrand() % 10000);
			}
			cnt++;
		}
	}
	// 99 - 133: random, elem < 1e6, 5 tests
	for (int i = 0; i < 7; i++) {
		for (int t = 0; t < 5; t++) {
			string s = "test" + to_string(cnt) + ".txt";
			freopen(s.c_str(), "w", stdout);
			printf("%d\n", N[i]);
			for (int j = 0; j < N[i]; j++) {
				printf("%d ", rrand() % 1000000);
			}
			fclose(stdout);
			cnt++;
		}
	}
	// 134 - 203: random, elem < 1e9, 10 tests
	for (int i = 0; i < 7; i++) {
		for (int t = 0; t < 10; t++) {
			string s = "test" + to_string(cnt) + ".txt";
			freopen(s.c_str(), "w", stdout);
			printf("%d\n", N[i]);
			for (int j = 0; j < N[i]; j++) {
				printf("%d ", rrand() % int(1e9));
			}
			fclose(stdout);
			cnt++;
		}
	}
}
