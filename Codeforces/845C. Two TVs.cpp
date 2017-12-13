/*
 * 845C. Two TVs.cpp
 *
 *  Created on: Dec 13, 2017
 *      Author: Osama Hatem
 */
 
/*
Sort the starts and ends of all intervals and process them in order. If at any
point the number of active/overlapping intervals is > 2, the answer is 'NO'.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	vector<pair<int, int>> evs;
	while (n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		evs.push_back(make_pair(a, 1));
		evs.push_back(make_pair(b + 1, -1));
	}
	int cnt = 0;
	bool ans = true;
	sort(evs.begin(), evs.end());
	for (auto p : evs) {
		cnt += p.second;
		ans &= cnt < 3;
	}
	printf("%s\n", ans ? "YES" : "NO");
	return 0;
}
