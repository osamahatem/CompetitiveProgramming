/*
 * G. Hey JUDgE.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[10];
int flag[5];

bool check() {
	for (int i = 0; i < 5; i++)
		if (!flag[i])
			return false;
	return true;
}

bool solve(int mask) {
	if (mask == (1 << 7) - 1)
		return check();
	bool ret = 0;
	int i = 0;
	for (i = 0; !ret && i < 7; i++) {
		if (mask & (1 << i))
			continue;
		break;
	}
	flag[in[i] - 'A']++;
	ret = ret || solve(mask | (1 << i));
	flag[in[i] - 'A']--;
	for (int j = i + 1; !ret && j < 7; j++) {
		if (mask & (1 << j))
			continue;
		int nw = in[i] - 'A' + in[j] - 'A' + 1;
		if (nw > 4)
			continue;
		flag[nw]++;
		ret = ret || solve(mask | (1 << i) | (1 << j));
		flag[nw]--;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("judge.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", in);
		printf("%s\n", (solve(0) ? "YES" : "NO"));
	}
	return 0;
}
