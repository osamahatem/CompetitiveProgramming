/*
 * 208D. Prizes, Prizes, more Prizes.cpp
 *
 *  Created on: Feb 23, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, p[55], a, b, c, d, e, cur = 0;
	long long ans[5];
	memset(ans, 0, sizeof ans);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	cin >> a >> b >> c >> d >> e;
	for (int i = 0; i < n; i++) {
		cur += p[i];
		int temp = cur / e;
		ans[4] += temp;
		cur -= temp * e;
		temp = cur / d;
		ans[3] += temp;
		cur -= temp * d;
		temp = cur / c;
		ans[2] += temp;
		cur -= temp * c;
		temp = cur / b;
		ans[1] += temp;
		cur -= temp * b;
		temp = cur / a;
		ans[0] += temp;
		cur -= temp * a;
	}
	for (int i = 0; i < 5; i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl << cur << endl;
	return 0;
}
