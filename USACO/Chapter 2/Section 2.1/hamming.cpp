/*
 ID: 19semse1
 PROG: hamming
 LANG: C++
 */
/*
 * hamming.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int ans[64];

int hamm(int a, int b) {
	int t = a ^ b;
	int ret = 0;
	while (t) {
		ret += t & 1;
		t /= 2;
	}
	return ret;
}

bool check(int n, int idx, int d) {
	for (int i = 0; i < idx; i++)
		if (hamm(n, ans[i]) < d)
			return false;
	return true;
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
//#endif

	int n, b, d, cnt = 1, cur = 1;
	cin >> n >> b >> d;
	cout << "0";
	for (int i = 1; i < n; i++) {
		while (!check(cur, i, d))
			cur++;
		ans[i] = cur++;
		if (cnt)
			cout << " ";
		cout << ans[i];
		cnt++;
		if (cnt == 10)
			cout << endl, cnt = 0;
	}
	if (cnt)
		cout << endl;
	return 0;
}
