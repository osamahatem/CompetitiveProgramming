/*
 * I. Coders' Race.cpp
 *
 *  Created on: Sep 6, 2015
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

	freopen("coder.in", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int l, n, m, mini = 1 << 20, arr[5005];
		string win, name;
		char in[25];
		scanf("%d%d%d", &l, &n, &m);
		while (n--) {
			scanf("%s", in);
			name = string(in);
			int sum = 0, ll = l, s = 0;
			for (int i = 0; i < m; i++) {
				scanf("%d", &arr[i]);
				sum += arr[i];
			}
			s = ll / sum * m;
			ll %= sum;
			for (int i = 0; i < m && ll > 0; i++)
				s++, ll -= arr[i];
			if (s < mini || (s == mini && name < win))
				mini = s, win = name;
		}
		cout << "Case " << t << ": " << win << endl;
	}
	return 0;
}
