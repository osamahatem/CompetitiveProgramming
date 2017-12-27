/*
 * 909B. Segments.cpp
 *
 *  Created on: Dec 27, 2017
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/56666

My solution is based on the same idea (overlapping segments must belong to
different layers), but I just count the maximum overlap in O(N^3) due to the
small constraints.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, ans = 0;
	cin >> n;
	for (int i = 0; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = i; k < j; k++)
				ans = max(ans, ++cnt[k]);
	cout << ans << endl;
	return 0;
}
