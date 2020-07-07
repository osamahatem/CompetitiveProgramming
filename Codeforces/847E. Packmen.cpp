/*
 * 847E. Packmen.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n;
char in[MAXN];

bool check(int t) {
	int last = -1;
	for (int i = 0; i < n; i++) {
		if (in[i] == '*' && last == -1)
			last = i;
		else if (in[i] == 'P') {
			int tt = t, cur = i;
			if (last != -1 && i - last > t)
				return false;
			if (last != -1)
				cur = last, tt -= i - last;
			int j = max(i, max(cur + tt, i + tt / 2));
			for (int k = i + 1; k <= min(j, n - 1); k++)
				if (in[k] == 'P') {
					j = k - 1;
					break;
				}
			i = j;
			last = -1;
		}
	}
	return last == -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%s", &n, in);
	int s = 0, e = n << 1;
	while (s < e) {
		int mid = (s + e) / 2;
		if (check(mid))
			e = mid;
		else
			s = mid + 1;
	}
	printf("%d\n", s);
	return 0;
}
