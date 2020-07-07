/*
 * 140B. New Year Cards.cpp
 *
 *  Created on: Apr 23, 2015
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

	int n, pr[305], pref[305][305], best[305], id[305];
	cin >> n;
	fill(best, best + n + 1, 500);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> pref[i][j];
	for (int i = 1; i <= n; i++)
		cin >> pr[i];
	for (int i = 1; i <= n; i++) {
		for (int f = 1; f <= n; f++) {
			int sent = 0;
			for (int j = 1; j <= n; j++) {
				if (pr[j] != f && pr[j] <= i) {
					sent = pr[j];
					break;
				}
			}
			for (int j = 1; j <= n; j++)
				if (pref[f][j] == sent && j <= best[f])
					best[f] = j, id[f] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i > 1)
			cout << " ";
		cout << id[i];
	}
	cout << endl;
	return 0;
}
