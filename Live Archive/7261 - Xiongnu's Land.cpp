/*
 * 7261 - Xiongnu's Land.cpp
 *
 *  Created on: Sep 24, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e4 + 5;

int n, R;
int s[MAXN], e[MAXN], h[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &R, &n);
		long long diff = 0;
		set<pair<int, int>> S, E;
		for (int i = 0; i < n; i++) {
			int w;
			scanf("%d%*d%d%d", &s[i], &w, &h[i]);
			e[i] = s[i] + w;
			diff -= 1ll * w * h[i];
			S.insert( { s[i], i });
		}
		int r = 0;
		long long H = 0;
		while (r <= R && diff < 0) {
			while (S.size() && S.begin()->first < r) {
				int id = S.begin()->second;
				S.erase(S.begin());
				E.insert( { e[id], id });
				H += h[id];
			}
			while (E.size() && E.begin()->first < r) {
				int id = E.begin()->second;
				E.erase(E.begin());
				H -= h[id];
			}
			diff += H * 2, r++;
		}
		long long area = diff;
		while (r <= R && diff == area) {
			while (S.size() && S.begin()->first < r) {
				int id = S.begin()->second;
				S.erase(S.begin());
				E.insert( { e[id], id });
				H += h[id];
			}
			while (E.size() && E.begin()->first < r) {
				int id = E.begin()->second;
				E.erase(E.begin());
				H -= h[id];
			}
			diff += H * 2;
			if (diff > area)
				break;
			r++;
		}
		printf("%d\n", r - 1);
	}
	return 0;
}
