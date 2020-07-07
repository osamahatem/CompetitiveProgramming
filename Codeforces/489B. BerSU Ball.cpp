/*
 * 489B. BerSU Ball.cpp
 *
 *  Created on: Jun 20, 2015
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

	int n, m, b[105], g[105], ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(b, b + n);
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> g[i];
	sort(g, g + m);
	for (int i = 0, j = 0; i < n && j < m; i++)
		if (abs(b[i] - g[j]) < 2)
			ans++, j++;
		else if (g[j] + 1 < b[i])
			j++, i--;
	cout << ans << endl;
	return 0;
}
