/*
 * 79B. Colorful Field.cpp
 *
 *  Created on: Apr 12, 2016
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

	string str[] = { "Carrots", "Kiwis", "Grapes", "Waste" };
	int H, W, k, t;
	scanf("%d%d%d%d", &H, &W, &k, &t);
	vector<int> waste(k);
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		waste[i] = a * W + b;
	}
	sort(waste.begin(), waste.end());
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		int cell = a * W + b;
		int idx = lower_bound(waste.begin(), waste.end(), cell) - waste.begin();
		int ans = 3;
		if (!(idx < (int) waste.size() && waste[idx] == cell))
			ans = (cell - idx) % 3;
		printf("%s\n", str[ans].c_str());
	}
	return 0;
}
