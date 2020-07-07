/*
 * 10169 - Urn-ball Probabilities!.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;
const double EPS = 1e-9;

double ans[MAXN];
int len[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	double prop = 1.0, cur = 1.0;
	for (int i = 1; i < MAXN; i++) {
		prop *= 1.0 - 1.0 / (1.0 * i * (i + 1));
		ans[i] = 1.0 - prop;
		cur *= 1.0 * i * (i + 1);
		len[i] = len[i - 1];
		while (cur - EPS > 10.0)
			len[i]++, cur /= 10.0;
	}
	cout << fixed << setprecision(6);
	int n;
	while (cin >> n)
		cout << ans[n] << " " << len[n] << endl;
	return 0;
}
