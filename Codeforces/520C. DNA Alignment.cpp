/*
 * 520C. DNA Alignment.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long MOD = 1000000007;

long long fastPower(long long b, long long p) {
	long long ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % MOD;
		b = b * b % MOD;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, maxi = 0, maxCnt = 0;
	string in;
	map<char, int> cnt;
	cin >> n >> in;
	for (int i = 0; i < n; i++)
		cnt[in[i]]++;
	for (map<char, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
		if (it->second == maxi)
			maxCnt++;
		else if (it->second > maxi)
			maxi = it->second, maxCnt = 1;
	cout << fastPower(maxCnt, n) << endl;
	return 0;
}
