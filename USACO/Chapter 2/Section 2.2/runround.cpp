/*
 ID: 19semse1
 PROG: runround
 LANG: C++
 */
/*
 * runround.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int M, num[9], mini = 1e9;

bool check(int len) {
	int i = 0, vis = 0;
	while (!(vis & (1 << i))) {
		vis |= 1 << i;
		i = (i + num[i]) % len;
	}
	return (!i && vis == (1 << len) - 1);
}

void generate(int cur, int len, int mask) {
	if (len > 9 || cur > mini)
		return;
	if (len && check(len) && cur < mini && cur > M) {
		mini = cur;
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (mask & (1 << (i - 1)))
			continue;
		int nmask = mask | (1 << (i - 1));
		int ncur = cur * 10 + i;
		num[len] = i;
		generate(ncur, len + 1, nmask);
	}
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
//#endif

	cin >> M;
	generate(0, 0, 0);
	cout << mini << endl;
	return 0;
}
