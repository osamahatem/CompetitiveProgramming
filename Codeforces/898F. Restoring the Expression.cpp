/*
 * 898F. Restoring the Expression.cpp
 *
 *  Created on: Dec 16, 2017
 *      Author: Osama Hatem
 */
 
/*
Try different possible sizes of the third part of the expression. The maximum
length of both other parts is either the length of the third part, or its length
- 1. We try all 4 possible combinations, if valid, and check using double
hashing in suitable time.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAXN = 1e6 + 5;

string in;
int sz;
long long h1[MAXN], h2[MAXN], r1, r2;

long long fastPower(long long b, long long p, long long mod) {
	long long ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % mod;
		b = b * b % mod;
	}
	return ret;
}

bool check(int a, int e) {
	if ((in[0] == '0' && a > 1) || (in[a] == '0' && e - a > 1)
			|| (in[e] == '0' && sz - e > 1))
		return false;

	long long x1 = (h1[0] - h1[a] + MOD1) % MOD1;
	x1 = x1 * fastPower(r1, sz - a, MOD1) % MOD1;
	long long y1 = (h1[a] - h1[e] + MOD1) % MOD1;
	y1 = y1 * fastPower(r1, sz - e, MOD1) % MOD1;
	long long z1 = h1[e];

	long long x2 = (h2[0] - h2[a] + MOD2) % MOD2;
	x2 = x2 * fastPower(r2, sz - a, MOD2) % MOD2;
	long long y2 = (h2[a] - h2[e] + MOD2) % MOD2;
	y2 = y2 * fastPower(r2, sz - e, MOD2) % MOD2;
	long long z2 = h2[e];

	return (x1 + y1) % MOD1 == z1 && (x2 + y2) % MOD2 == z2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> in;
	sz = (int) in.size();

	long long p1 = 1, p2 = 1;
	for (int i = sz - 1; ~i; i--) {
		h1[i] = (h1[i + 1] + p1 * (in[i] - '0')) % MOD1;
		h2[i] = (h2[i + 1] + p2 * (in[i] - '0')) % MOD2;
		p1 = p1 * 10 % MOD1, p2 = p2 * 10 % MOD2;
	}
	r1 = fastPower(10, MOD1 - 2, MOD1);
	r2 = fastPower(10, MOD2 - 2, MOD2);

	int a = -1, e = -1;
	for (int i = 1; i < sz; i++) {
		if (i * 2 < sz - i)
			continue;
		if (sz - i < i)
			break;
		int len = i - 1;
		if (sz - i - len <= len && check(len, sz - i)) {
			a = len, e = sz - i;
			break;
		}
		if (sz - i - len <= len && check(sz - i - len, sz - i)) {
			a = sz - i - len, e = sz - i;
			break;
		}
		len = i;
		if (sz - i - len <= len && check(len, sz - i)) {
			a = len, e = sz - i;
			break;
		}
		if (sz - i - len <= len && check(sz - i - len, sz - i)) {
			a = sz - i - len, e = sz - i;
			break;
		}
	}
	cout << in.substr(0, a) << '+' << in.substr(a, e - a) << '='
			<< in.substr(e, sz) << endl;
	return 0;
}
