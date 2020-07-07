/*
 * 536B. Tavas and Malekas.cpp
 *
 *  Created on: Apr 14, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;
const long long MOD = 1000000007;

string p;
int match[MAXN], fail[MAXN];
bool valid[MAXN];

void calcFail() {
	fail[0] = 0;
	int len = 0;
	for (int i = 1; i < (int) p.size(); i++) {
		while (len && p[len] != p[i])
			len = fail[len - 1];
		if (p[len] == p[i])
			len++;
		fail[i] = len;
	}
}

long long fastPower(long long base, long long power) {
	long long ret = 1;
	for (; power; power >>= 1) {
		if (power & 1)
			ret = ret * base % MOD;
		base = base * base % MOD;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, last = -1;
	long long ans = 1;
	cin >> n >> m >> p;
	int len = (int) p.size();
	for (int i = 0; i < m; i++)
		cin >> match[i], match[i]--;
	calcFail();
	int tlen = len - 1;
	while (tlen > 0)
		valid[fail[tlen]] = 1, tlen = fail[tlen] - 1;
	for (int i = 0; i < m; i++) {
		if (match[i] > last)
			ans = ans * fastPower(26, match[i] - last - 1) % MOD;
		else if (!valid[last - match[i] + 1])
			ans *= 0;
		last = match[i] + len - 1;
	}
	if (n > last)
		ans = ans * fastPower(26, n - last - 1) % MOD;
	cout << ans << endl;
	return 0;
}
