/*
 * 489A. SwapSort.cpp
 *
 *  Created on: Jun 20, 2015
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

	int n, arr[3005];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		int mini = arr[i], id = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < mini)
				mini = arr[j], id = j;
		ans.push_back(make_pair(i, id));
		swap(arr[i], arr[id]);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}
