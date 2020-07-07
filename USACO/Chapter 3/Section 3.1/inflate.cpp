/*
 ID: 19semse1
 PROG: inflate
 LANG: C++
 */
/*
 * inflate.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct quest {
	int t, s;
};

int dp[10001];
quest all[10001];

int main() {
//#ifndef ONLINE_JUDGE
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);
//#endif

	int T, N;
	cin >> T >> N;
	for (int i = 0; i < N; i++)
		cin >> all[i].s >> all[i].t;
	for (int i = 1; i <= T; i++)
		for (int j = 0; j < N; j++)
			if (all[j].t <= i)
				dp[i] = max(dp[i], dp[i - all[j].t] + all[j].s);
	cout << dp[T] << endl;
	return 0;
}
