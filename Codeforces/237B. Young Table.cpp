/*
 * 237B. Young Table.cpp
 *
 *  Created on: Aug 11, 2015
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

	int n, c[55], t[55][55], s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		s += c[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < c[i]; j++)
			cin >> t[i][j];
	vector<pair<pair<int, int>, pair<int, int>>> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < c[i]; j++) {
			int mini = t[i][j], mi = i, mj = j;
			for (int ii = i; ii < n; ii++)
				for (int jj = (ii == i ? j : 0); jj < c[ii]; jj++)
					if (t[ii][jj] < mini)
						mini = t[ii][jj], mi = ii, mj = jj;
			swap(t[i][j], t[mi][mj]);
			if (i != mi || j != mj)
				ans.push_back(make_pair(make_pair(i, j), make_pair(mi, mj)));
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++) {
		cout << ++ans[i].first.first << " " << ++ans[i].first.second << " ";
		cout << ++ans[i].second.first << " " << ++ans[i].second.second << endl;
	}
	return 0;
}
