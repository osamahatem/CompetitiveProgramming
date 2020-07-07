/*
 * 950B. Intercepted Message.cpp
 *
 *  Created on: Apr 9, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, a[MAXN], b[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	int ans = 0;
	for (int i = 0, j = 0, s1 = 0, s2 = 0; i < n && j < m; ans++) {
		while (!s1 || !s2 || s1 != s2) {
			if (s1 < s2)
				s1 += a[i++];
			else
				s2 += b[j++];
		}
		s1 = s2 = 0;
	}
	cout << ans << endl;
	return 0;
}
