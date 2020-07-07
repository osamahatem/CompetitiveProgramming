/*
 * 234D. Cinema.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int mini[105], maxi[105];

int main() {
//#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//#endif

	int n, m, k, a;
	set<int> fav;
	cin >> m >> k;
	while (k--) {
		cin >> a;
		fav.insert(a);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int fav_cnt = 0, left = 0, norm_cnt = 0;
		cin >> name >> k;
		while (k--) {
			cin >> a;
			if (!a)
				left++;
			else if (fav.count(a))
				fav_cnt++;
			else
				norm_cnt++;
		}
		mini[i] = fav_cnt + max(0, left - m + norm_cnt + (int) fav.size());
		maxi[i] = fav_cnt + min(left, (int) fav.size() - fav_cnt);
	}
	for (int i = 0; i < n; i++) {
		bool can = 1, is = 1;
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			if (maxi[i] < mini[j])
				can = is = 0;
			if (mini[i] < maxi[j])
				is = 0;
		}
		cout << (is ? 0 : (can ? 2 : 1)) << endl;
	}
	return 0;
}
