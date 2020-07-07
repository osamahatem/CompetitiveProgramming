/*
 * 471D. MUH and Cube Walls.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int N, W, nt[MAXN], wt[MAXN], wdif[MAXN], ndif[MAXN], fail[MAXN], ans;

void computeFail() {
	fail[0] = 0;
	int cur = 0;
	for (int i = 1; i + 1 < W; i++) {
		while (cur && wdif[cur] != wdif[i])
			cur = fail[cur - 1];
		if (wdif[cur] == wdif[i])
			cur++;
		fail[i] = cur;
	}
}

void genMatch() {
	int cur = 0;
	for (int i = 0; i + 1 < N; i++) {
		while (cur && wdif[cur] != ndif[i])
			cur = fail[cur - 1];
		if (wdif[cur] == ndif[i])
			cur++;
		if (cur == W - 1)
			ans++, cur = fail[cur - 1];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> N >> W;
	if (W == 1) {
		cout << N << endl;
		return 0;
	}
	if (W > N) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < N; i++)
		cin >> nt[i];
	for (int i = 0; i < W; i++)
		cin >> wt[i];
	for (int i = 0; i + 1 < W; i++)
		wdif[i] = wt[i] - wt[i + 1];
	for (int i = 0; i + 1 < N; i++)
		ndif[i] = nt[i] - nt[i + 1];
	computeFail();
	genMatch();
	cout << ans << endl;
	return 0;
}
