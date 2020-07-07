/*
 * 496D. Tennis Game.cpp
 *
 *  Created on: Dec 17, 2014
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

	int n, x, tta1 = 0, tta2 = 0, fa1[100005], fa2[100005];
	pair<int, int> scores[100005];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 1)
			tta1++, fa1[tta1] = i;
		else
			tta2++, fa2[tta2] = i;
		scores[i].first = tta1;
		scores[i].second = tta2;
	}
	int maxi = max(tta1, tta2);
	vector<pair<int, int> > ans;
	for (int i = 1; i <= maxi; i++) {
		int last = 0, a1 = 0, a2 = 0;
		int c1 = 0, c2 = 0;
		while (1) {
			int f = 1 << 28;
			if (a1 + i <= tta1)
				f = min(f, fa1[a1 + i]);
			if (a2 + i <= tta2)
				f = min(f, fa2[a2 + i]);
//			cout << a1 << " " << a2 << " " << i << " " << fa1[a1 + i] << " "
//					<< fa2[a2 + i] << endl;
			if (f == 1 << 28)
				break;
			int ta1 = scores[f].first;
			int ta2 = scores[f].second;
			if (ta1 - a1 == i)
				last = 1, c1++;
			else
				last = 2, c2++;
			a1 = ta1;
			a2 = ta2;
		}
		if (a1 == tta1 && a2 == tta2
				&& ((last == 1 && c1 > c2) || (last == 2 && c2 > c1)))
			ans.push_back(make_pair(max(c1, c2), i));
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}
