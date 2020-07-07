/*
 * B. Airports.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int arr[100005][4];
bool vis[100005];
priority_queue<pair<int, int>> sums[4];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		arr[i][0] = x + y;
		arr[i][1] = x - y;
		arr[i][2] = -x + y;
		arr[i][3] = -x - y;
		sums[0].push(make_pair(arr[i][0], i));
		sums[1].push(make_pair(arr[i][1], i));
		sums[2].push(make_pair(arr[i][2], i));
		sums[3].push(make_pair(arr[i][3], i));
	}
	int maxi[4];
	for (int i = 0; i < 4; i++)
		maxi[i] = arr[0][i];
	int ans = 2e9 + 5, cnt = 1;
	vis[0] = 1;
	while (cnt < n) {
		for (int i = 0; i < 4; i++)
			while (vis[sums[i].top().second])
				sums[i].pop();
		int newCost = 0, newNode = -1;
		for (int i = 0; i < 4; i++)
			if (maxi[i] + sums[3 - i].top().first > newCost) {
				newCost = maxi[i] + sums[3 - i].top().first;
				newNode = sums[3 - i].top().second;
			}
		vis[newNode] = 1;
		ans = min(ans, newCost);
		for (int i = 0; i < 4; i++)
			maxi[i] = max(maxi[i], arr[newNode][i]);
		cnt++;
	}
	printf("%d\n", ans);
	return 0;
}
