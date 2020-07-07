/*
 * E. Shi's throne.cpp
 *
 *  Created on: Aug 30, 2015
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

	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> all(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &all[i]);
	sort(all.begin(), all.end());
	printf("%d\n", all[--m]);
	return 0;
}
