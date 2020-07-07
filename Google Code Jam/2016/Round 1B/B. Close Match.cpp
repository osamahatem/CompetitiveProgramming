/*
 * B. Close Match.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long INF = 1ll << 62;

long long powTen[18];
string C, J;
int len, clen, jlen;
long long dp[20][3][2];
pair<int, int> path[20][3][2];

long long solve(int idx, int flag, bool big) {
	if (idx == len)
		return 0;
	long long &ret = dp[idx][flag][big];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 0; i < 10; i++) {
		if (C[idx] != '?' && C[idx] - '0' != i)
			continue;
		for (int j = 0; j < 10; j++) {
			if (J[idx] != '?' && J[idx] - '0' != j)
				continue;
			int newFlag = flag;
			if (flag == 1 && i < j)
				newFlag = 0;
			else if (flag == 1 && i > j)
				newFlag = 2;
			if ((!big && newFlag == 2) || (big && newFlag == 0))
				continue;
			long long temp = powTen[len - idx - 1] * (big ? i - j : j - i)
					+ solve(idx + 1, newFlag, big);
			if (temp < ret) {
				ret = temp;
				path[idx][flag][big] = make_pair(i, j);
			}
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	powTen[0] = 1;
	for (int i = 1; i < 18; i++)
		powTen[i] = powTen[i - 1] * 10;
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(dp, -1, sizeof dp);
		cout << "Case #" << t << ": ";
		cin >> C >> J;
		clen = C.size(), jlen = J.size();
		while (C.size() < J.size())
			C = "0" + C;
		while (J.size() < C.size())
			J = "0" + J;
		len = C.size();
		string C1 = C, C2 = C, J1 = J, J2 = J;
		long long ans1 = solve(0, 1, 0), ans2 = solve(0, 1, 1);
		int flag = 1, big = 0;
		for (int i = 0; i < len; i++) {
			int a = path[i][flag][big].first;
			int b = path[i][flag][big].second;
			C1[i] = a + '0';
			J1[i] = b + '0';
			if (flag == 1 && a < b)
				flag = 0;
			else if (flag == 1 && a > b)
				flag = 2;
		}
		flag = 1, big = 1;
		for (int i = 0; i < len; i++) {
			int a = path[i][flag][big].first;
			int b = path[i][flag][big].second;
			C2[i] = a + '0';
			J2[i] = b + '0';
			if (flag == 1 && a < b)
				flag = 0;
			else if (flag == 1 && a > b)
				flag = 2;
		}
		if (ans1 < ans2 || (ans1 == ans2 && C1 < C2)
				|| (ans1 == ans2 && C1 == C2 && J1 < J2))
			C = C1, J = J1;
		else
			C = C2, J = J2;
		cout << C.substr(len - clen, clen) << " " << J.substr(len - jlen, jlen)
				<< endl;
	}
	return 0;
}
