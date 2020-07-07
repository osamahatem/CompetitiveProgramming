/*
 * 583A. Asphalting Roads.cpp
 *
 *  Created on: Oct 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool v1[55], v2[55];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	bool sp = 0;
	cin >> n;
	n *= n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		if (!v1[x] && !v2[y]) {
			v1[x] = v2[y] = 1;
			if (sp)
				cout << " ";
			cout << i;
			sp = 1;
		}
	}
	cout << endl;
	return 0;
}
