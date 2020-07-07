/*
 * K. Mixing Bowls.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, r, ans, bowls;
map<string, int> rnk;
vector<vector<int>> adj;
char buff[25];

int solve(int idx) {
	vector<int> temp;
	for (int i = 0; i < (int) adj[idx].size(); i++)
		temp.push_back(solve(adj[idx][i]));
	if (temp.empty())
		return 1;
	int ret = 0;
	sort(temp.begin(), temp.end(), greater<int>());
	for (int i = 0; i < (int) temp.size(); i++)
		ret = max(ret, i + temp[i]);
	if ((int) temp.size() == ret)
		ret++;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	adj.assign(n, vector<int>());
	for (int i = 0; i < n; i++) {
		int x, cur;
		scanf("%s%d", buff, &x);
		if (!rnk.count(buff))
			rnk[buff] = r++;
		cur = rnk[buff];
		while (x--) {
			scanf("%s", buff);
			if (buff[0] >= 'a')
				continue;
			if (!rnk.count(buff))
				rnk[buff] = r++;
			adj[cur].push_back(rnk[buff]);
		}
	}
	printf("%d\n", solve(0));
	return 0;
}
