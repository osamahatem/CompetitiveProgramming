/*
 * 12C. Fruits.cpp
 *
 *  Created on: Aug 30, 2015
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

	int n, m, pr[105];
	map<string, int> cnt;
	vector<int> cnts;
	string fruit;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> pr[i];
	while (m--) {
		cin >> fruit;
		cnt[fruit]++;
	}
	for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
		cnts.push_back(it->second);
	int mini = 0, maxi = 0;
	sort(pr, pr + n);
	sort(cnts.begin(), cnts.end(), greater<int>());
	for (int i = 0; i < (int) cnts.size(); i++)
		mini += pr[i] * cnts[i], maxi += pr[n - i - 1] * cnts[i];
	cout << mini << " " << maxi << endl;
	return 0;
}
