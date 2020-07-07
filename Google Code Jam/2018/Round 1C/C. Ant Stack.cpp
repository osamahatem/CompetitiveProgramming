/*
 * C. Ant Stack.cpp
 *
 *  Created on: May 5, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXL = 205;

int n, w[MAXN];
long long mini[MAXL], temp[MAXL];

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(mini, -1, sizeof mini);
		mini[0] = 0;

		int ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> w[i];
			memcpy(temp, mini, sizeof mini);
			for (int l = 1; l < MAXL; l++) {
				if (mini[l - 1] != -1 && mini[l - 1] <= 6ll * w[i]) {
					long long new_w = mini[l - 1] + w[i];
					if (mini[l] != -1)
						new_w = min(new_w, mini[l]);
					temp[l] = new_w;
					ans = max(ans, l);
				}
			}
			memcpy(mini, temp, sizeof mini);
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
