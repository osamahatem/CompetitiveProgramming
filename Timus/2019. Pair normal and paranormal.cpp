/*
 * 2019. Pair: normal and paranormal.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5005;

int n, prv[2 * MAXN], ans[2 * MAXN], id[2 * MAXN];
string in;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int c1 = 0, c2 = 0;
	cin >> n >> in;
	for (int i = 0; i < 2 * n; i++) {
		prv[i] = i - 1, ans[i] = -1;
		if (isupper(in[i]))
			id[i] = ++c1;
		else
			id[i] = ++c2;
	}
	for (int i = 0; i + 1 < 2 * n; i++) {
		if (abs(in[i] - in[i + 1]) == 32) {
			int s = i, e = i + 1;
			while (s >= 0 && e < 2 * n && abs(in[s] - in[e]) == 32) {
				if (isupper(in[s]))
					ans[s] = id[e];
				else
					ans[e] = id[s];
				s = prv[s];
				e++;
			}
			prv[e] = s;
			i = --e;
		}
	}
	for (int i = 0; i < 2 * n; i++) {
		if (isupper(in[i]) && ans[i] == -1) {
			cout << "Impossible\n";
			return 0;
		}
	}
	bool sp = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (isupper(in[i])) {
			if (sp)
				cout << " ";
			cout << ans[i];
			sp = 1;
		}
	}
	cout << endl;
	return 0;
}
