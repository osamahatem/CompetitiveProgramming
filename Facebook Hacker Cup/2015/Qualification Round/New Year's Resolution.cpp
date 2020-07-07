/*
 * New Year's Resolution.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int t, tc = 0;
	cin >> t;
	while (t--) {
		cout << "Case #" << ++tc << ": ";
		int n, gc, gp, gf, c[20], p[20], f[20];
		bool ans = 0;
		cin >> gc >> gp >> gf >> n;
		for (int i = 0; i < n; i++)
			cin >> c[i] >> p[i] >> f[i];
		for (int i = 0; i < (1 << n); i++) {
			int sc = 0, sp = 0, sf = 0;
			for (int j = 0; j < n; j++)
				if (i & (1 << j))
					sc += c[j], sp += p[j], sf += f[j];
			if (sc == gc && sp == gp && sf == gf)
				ans = 1;
		}
		cout << (ans ? "yes" : "no") << endl;
	}
	return 0;
}
