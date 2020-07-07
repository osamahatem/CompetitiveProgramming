/*
 * 508C. Anya and Ghosts.cpp
 *
 *  Created on: Jan 27, 2015
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

	int m, t, r, gt[305], ans = 0;
	bool cndl[605];
	memset(cndl, 0, sizeof cndl);
	cin >> m >> t >> r;
	for (int i = 0; i < m; i++)
		cin >> gt[i], gt[i] += 300;
	if (t < r) {
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 0; i < m; i++) {
		int temp = r;
		for (int j = gt[i] - 1; j >= gt[i] - t; j--)
			temp -= cndl[j];
		for (int j = gt[i] - 1; j >= gt[i] - t && temp > 0; j--)
			if (!cndl[j])
				cndl[j] = 1, temp--, ans++;
		if (temp > 0) {
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}
