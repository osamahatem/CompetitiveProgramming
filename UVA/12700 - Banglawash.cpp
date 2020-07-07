/*
 * 12700 - Banglawash.cpp
 *
 *  Created on: Aug 9, 2014
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

	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int n, b = 0, w = 0;
		string s;
		cin >> n >> s;
		for (int i = 0; i < (int) s.size(); i++) {
			if (s[i] == 'A')
				n--;
			else if (s[i] == 'W')
				w++;
			else if (s[i] == 'B')
				b++;
		}
		printf("Case %d: ", tc);
		if (n == 0)
			printf("ABANDONED");
		else if (b == n)
			printf("BANGLAWASH");
		else if (w == n)
			printf("WHITEWASH");
		else if (b > w)
			printf("BANGLADESH %d - %d", b, w);
		else if (w > b)
			printf("WWW %d - %d", w, b);
		else
			printf("DRAW %d %d", w, n - w - b);
		printf("\n");
	}
	return 0;
}
