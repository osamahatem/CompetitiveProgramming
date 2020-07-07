/*
 * 319B. Psychos in a Line.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, id[MAXN], tDeath[MAXN], ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> id[i];
	tDeath[0] = -1;
	stack<int> S;
	S.push(0);
	for (int i = 1; i < n; i++) {
		if (id[S.top()] > id[i])
			tDeath[i] = 0;
		else {
			int maxi = 0;
			while (S.size() && id[S.top()] < id[i])
				maxi = max(maxi, tDeath[S.top()]), S.pop();
			if (S.empty())
				tDeath[i] = -1;
			else
				tDeath[i] = maxi + 1;
		}
		S.push(i);
		ans = max(ans, tDeath[i] + 1);
	}
	cout << ans << endl;
	return 0;
}
