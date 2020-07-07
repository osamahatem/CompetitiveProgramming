/*
 * H. Graduation Projects (B).cpp
 *
 *  Created on: Sep 3, 2015
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

	int n, gr[105];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> gr[i * 2] >> gr[i * 2 + 1];
	sort(gr, gr + 2 * n);
	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		cout << gr[i] << " " << gr[2 * n - 1 - i];
	}
	cout << endl;
	return 0;
}
