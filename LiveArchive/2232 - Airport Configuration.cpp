/*
 * 2232 - Airport Configuration.cpp
 *
 *  Created on: Dec 9, 2017
 *      Author: Osama Hatem
 */
 
/*
This problem is an easy and straightforward. For every trip description, simply
multiply the number of passengers by the distance between the corresponding
gates and add it to the total answer, then sort in the end.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<vector<pair<int, int>>> cities;
int arr[25], dep[25];
vector<pair<int, int>> res;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	while (scanf("%d", &n), n) {
		res.clear();
		cities.clear();
		cities.resize(n);
		for (int i = 0; i < n; i++) {
			int id, k;
			scanf("%d%d", &id, &k);
			cities[--id].resize(k);
			for (int j = 0; j < k; j++) {
				scanf("%d%d", &cities[id][j].first, &cities[id][j].second);
				cities[id][j].first--;
			}
		}
		int id;
		while (scanf("%d", &id), id) {
			int x;
			for (int i = 0; i < n; i++) {
				scanf("%d", &x);
				arr[--x] = i;
			}
			for (int i = 0; i < n; i++) {
				scanf("%d", &x);
				dep[--x] = i;
			}
			int ans = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < (int) cities[i].size(); j++)
					ans += cities[i][j].second
							* (1 + abs(arr[i] - dep[cities[i][j].first]));
			res.push_back(make_pair(ans, id));
		}
		sort(res.begin(), res.end());
		printf("Configuration Load\n");
		for (int i = 0; i < (int) res.size(); i++)
			printf("%5d         %d\n", res[i].second, res[i].first);
	}
	return 0;
}
