/*
 * E. Bravebeart.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, w[50], h[50];
bool vis[50];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	cin >> T;
	while (T--) {
		memset(vis, 0, sizeof vis);
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> w[i];
		int lim = 0, id = -1, maxi;
		for (int i = 0; i < n; i++) {
			cin >> h[i];
			if (w[0] * h[i] > lim)
				lim = w[0] * h[i], id = i;
		}
		vis[id] = 1;
		bool flag = 1;
		for (int i = 1; i < n; i++) {
			maxi = 0, id = -1;
			for (int j = 0; j < n; j++)
				if (!vis[j] && w[i] * h[j] < lim && w[i] * h[j] > maxi)
					maxi = w[i] * h[j], id = j;
			if (id == -1)
				flag = 0;
			else
				vis[id] = 1;
		}
		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}
