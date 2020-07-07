/*
 ID: 19semse1
 PROG: kimbits
 LANG: C++
 */
/*
 * kimbits.cpp
 *
 *  Created on: Mar 25, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long cnt[32][32];

long long init(int n, int l) {
	if (!n)
		return cnt[0][l] = 1;
	long long &ret = cnt[n][l];
	if (ret != -1)
		return ret;
	ret = 0;
	if (l)
		ret += init(n - 1, l - 1);
	ret += init(n - 1, l);
	return ret;
}

void solve(int n, int l, long long i) {
	if (!n)
		return;
	if (cnt[n - 1][l] >= i) {
		cout << '0';
		solve(n - 1, l, i);
		return;
	}
	i -= cnt[n - 1][l];
	cout << '1';
	solve(n - 1, l - 1, i);
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("kimbits.in", "r", stdin);
	freopen("kimbits.out", "w", stdout);
//#endif

	memset(cnt, -1, sizeof cnt);
	int n, l;
	long long i;
	cin >> n >> l >> i;
	init(n, l);
	solve(n, l, i);
	cout << endl;
	return 0;
}
