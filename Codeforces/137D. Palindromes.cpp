/*
 * 137D. Palindromes.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 505;

string S;
int steps[MAXN][MAXN], dp[MAXN][MAXN], path[MAXN][MAXN], sz;

void getSteps(int s, int e) {
	int cnt = 0;
	for (int ss = s, ee = e; ss < ee; ss++, ee--)
		cnt += S[ss] != S[ee];
	steps[s][e] = cnt;
}

int solve(int idx, int k) {
	if (idx < sz && !k)
		return 1 << 20;
	if (idx == sz)
		return 0;
	int &ret = dp[idx][k];
	if (ret != -1)
		return ret;
	ret = 1 << 20;
	for (int e = idx; e < sz; e++) {
		int val = steps[idx][e] + solve(e + 1, k - 1);
		if (val < ret)
			ret = val, path[idx][k] = e;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	int k;
	cin >> S >> k;
	sz = S.size();
	for (int s = 0; s < sz; s++)
		for (int e = s; e < sz; e++)
			getSteps(s, e);
	cout << solve(0, k) << endl;
	int cur = 0;
	for (int kk = k; cur < sz; kk--) {
		if (cur)
			cout << "+";
		string temp = S.substr(cur, path[cur][kk] - cur + 1);
		int szz = temp.size();
		cur = path[cur][kk] + 1;
		for (int i = 0; i < szz; i++)
			temp[i] = temp[szz - i - 1];
		cout << temp;
	}
	cout << endl;
	return 0;
}
