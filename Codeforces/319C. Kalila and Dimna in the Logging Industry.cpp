/*
 * 319C. Kalila and Dimna in the Logging Industry.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const double EPS = 1e-9;

int n, a[MAXN], b[MAXN];
long long dp[MAXN];
vector<long long> inters;
vector<int> ID;

long long getInter(long long m1, long long c1) {
	int lastID = ID.back();
	long long m2 = b[lastID], c2 = dp[lastID];
	double ret = (double) (c2 - c1) / (m1 - m2);
	return (long long) (ceil(ret) + EPS);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	dp[0] = 0;
	inters.push_back(-(1 << 28)), ID.push_back(0);
	for (int i = 1; i < n; i++) {
		int best = upper_bound(inters.begin(), inters.end(), a[i])
				- inters.begin() - 1;
		int bestID = ID[best];
		dp[i] = dp[bestID] + (long long) a[i] * b[bestID];
		while (getInter(b[i], dp[i]) <= inters.back())
			inters.pop_back(), ID.pop_back();
		inters.push_back(getInter(b[i], dp[i])), ID.push_back(i);
	}
	cout << dp[n - 1] << endl;
	return 0;
}
