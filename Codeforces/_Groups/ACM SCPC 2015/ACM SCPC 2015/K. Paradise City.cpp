/*
 * K. Paradise City.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[3][305];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("city.in", "r", stdin);
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < 3; i++)
			scanf("%s", in[i]);
		int ans = 0;
		for (int s = 0; s < n * 3; s += 3) {
			int temp = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					if (in[i][s + j] == '*')
						temp += 4;
			ans = max(ans, temp);
		}
		printf("%d\n", ans);
	}
	return 0;
}
