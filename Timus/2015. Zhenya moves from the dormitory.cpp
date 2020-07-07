/*
 * 2015. Zhenya moves from the dormitory.cpp
 *
 *  Created on: Nov 8, 2014
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

	int pay, a1, a2, n, m;
	cin >> pay >> a1 >> a2;
	cin >> n;
	vector<pair<int, int> > all(n);
	for (int i = 0; i < n; i++)
		cin >> all[i].first >> all[i].second;
	cin >> m;
	int maxi = -1, maxID = -1, maxF = -1;
	for (int i = 0; i < m; i++) {
		int t, rent, ad;
		cin >> t >> rent >> ad;
		if (t == 1 && pay >= rent && a1 + ad > maxi) {
			maxi = a1 + ad;
			maxID = i;
			maxF = -1;
		}
		if (t == 1)
			continue;
		if (t == 2 && pay >= rent && a2 + ad > maxi) {
			maxi = a2 + ad;
			maxID = i;
			maxF = -1;
		}
		for (int j = 0; j < n; j++)
			if (pay * 2 >= rent && all[j].first * 2 >= rent
					&& ad + all[j].second > maxi) {
				maxi = ad + all[j].second;
				maxID = i;
				maxF = j;
			}
	}
	if (maxi == -1)
		cout << "Forget about apartments. Live in the dormitory.\n";
	else {
		cout << "You should rent the apartment #" << ++maxID << " ";
		if (maxF == -1)
			cout << "alone.\n";
		else
			cout << "with the friend #" << ++maxF << ".\n";
	}
	return 0;
}
