/*
 * B. Ascencion.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[300], need[300];
string name[105], gang[105], temp;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int k, best = -1;
	string bname, bgang;
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> name[i] >> gang[i];
	for (int i = 0; i < k; i++) {
		memset(cnt, 0, sizeof cnt);
		memset(need, 0, sizeof need);
		for (int j = 0; j < (int) name[i].size(); j++)
			need[name[i][j]]++;
		for (int j = 0; j < (int) gang[i].size(); j++)
			need[gang[i][j]]++;
		int n, m;
		cin >> n >> m;
		while (n--) {
			cin >> temp;
			for (int i = 0; i < m; i++)
				cnt[temp[i]]++;
		}
		int curAns = 1e6;
		for (int i = 0; i < 300; i++)
			if (need[i])
				curAns = min(curAns, cnt[i] / need[i]);
		if (curAns > best)
			best = curAns, bname = name[i], bgang = gang[i];
	}
	cout << bname << " " << bgang << endl;
	return 0;
}
