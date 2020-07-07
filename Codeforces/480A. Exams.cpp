/*
 * 480A. Exams.cpp
 *
 *  Created on: Oct 19, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<pair<int, int> > all(n);
	for (int i = 0; i < n; i++)
		cin >> all[i].first >> all[i].second;
	sort(all.begin(), all.end());
	int ans = all[0].second;
	for (int i = 1; i < n; i++){
		if(all[i].second >= ans)
			ans = all[i].second;
		else
			ans = all[i].first;
	}
	cout << ans << endl;
	return 0;
}
