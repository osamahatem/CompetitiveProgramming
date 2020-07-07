/*
 * G. Game for Little Johnny.cpp
 *
 *  Created on: Oct 3, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n;
vector<int> divs[MAXN];
int used[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			divs[j].push_back(i);
	int ans = 0;
	for (int a = 1; a <= n; a++) {
		for (int x = a; x <= n; x += a) {
			int lft = n - x;
			for (int i = (int) divs[lft].size() - 1; ~i && divs[lft][i] > a;
					i--)
				if (used[divs[lft][i]] != a)
					ans++, used[divs[lft][i]] = a;
		}
	}
	printf("%d\n", ans);
	return 0;
}
