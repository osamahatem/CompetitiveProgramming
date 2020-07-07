/*
 * 11242 - Tour de France.cpp
 *
 *  Created on: Sep 30, 2014
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

	int f, r, front[10], rear[10];
	while (cin >> f, f) {
		cin >> r;
		for (int i = 0; i < f; i++)
			cin >> front[i];
		for (int i = 0; i < r; i++)
			cin >> rear[i];
		vector<double> all;
		for (int i = 0; i < f; i++)
			for (int j = 0; j < r; j++)
				all.push_back((double) front[i] / rear[j]);
		sort(all.begin(), all.end());
		double ans = 0.0;
		for (int i = 1; i < (int) all.size(); i++)
			ans = max(ans, all[i] / all[i - 1]);
		printf("%.2f\n", ans);
	}
	return 0;
}
