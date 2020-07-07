/*
 * 388C. Fox and Card Game.cpp
 *
 *  Created on: Aug 7, 2016
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

	int n, sum = 0, ciel = 0;
	vector<int> maxi;
	scanf("%d", &n);
	while (n--) {
		int s;
		scanf("%d", &s);
		for (int i = 0; i < s; i++) {
			int x;
			scanf("%d", &x);
			sum += x;
			if (i < s / 2)
				ciel += x;
			if ((s & 1) && i == s / 2)
				maxi.push_back(x);
		}
	}
	sort(maxi.begin(), maxi.end(), greater<int>());
	for (int i = 0; i < (int) maxi.size(); i += 2)
		ciel += maxi[i];
	printf("%d %d\n", ciel, sum - ciel);
	return 0;
}
