/*
 * J.  Jurisdiction Disenchantment.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int x, y;

	static const bool byX(const node& a, const node& b) {
		return a.x < b.x;
	}
};

int n;
node arr[300];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &arr[i].x, &arr[i].y);
		sort(arr, arr + n, node::byX);
		int ans = 1 << 30, lim = n / 2 + 1;
		for (int i = 0; i < n; i++) {
			for (int j = i + lim - 1; j < n; j++) {
				vector<int> temp;
				for (int k = i; k <= j; k++)
					temp.push_back(arr[k].y);
				sort(temp.begin(), temp.end());
				for (int k = lim - 1; k < (int) temp.size(); k++)
					ans = min(ans,
							(arr[j].x - arr[i].x)
									* (temp[k] - temp[k - lim + 1]));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
