/*
 * H. Sieve Coding.cpp
 *
 *  Created on: May 1, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N;
char in[260], grid[18][18];
set<pair<int, int>> vis;

pair<int, int> rotate(pair<int, int> p) {
	p.first *= 2, p.second *= 2;
	int dx = p.first - N + 1, dy = p.second - N + 1;
	swap(dx, dy);
	dy *= -1;
	return make_pair((N - 1 + dx) / 2, (N - 1 + dy) / 2);
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("sieve.in", "r", stdin);
	freopen("sieve.out", "w", stdout);
//#endif

	scanf("%s%d", in, &N);
	for (int i = 0; i < N; i++)
		scanf("%s", grid[i]);
	int len = strlen(in);
	if (N * N < len) {
		printf("No solution.\n");
		return 0;
	}
	vector<pair<int, int>> visible;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (grid[i][j] == '+')
				visible.push_back(make_pair(i, j));
	memset(grid, '*', sizeof grid);
	int idx = 0;
	for (int i = 0; i < N && idx < len; i++)
		for (int j = 0; j < N && idx < len; j++)
			grid[i][j] = in[idx++];
	string ans = "";
	for (int s = 0; s < 4; s++) {
		sort(visible.begin(), visible.end());
		for (int i = 0; i < (int) visible.size(); i++) {
			if (vis.count(visible[i])) {
				printf("No solution.\n");
				return 0;
			} else {
				vis.insert(visible[i]);
				ans += grid[visible[i].first][visible[i].second];
			}
			visible[i] = rotate(visible[i]);
		}
	}
	if ((int) vis.size() != N * N) {
		printf("No solution.\n");
		return 0;
	}
	printf("%s\n", ans.c_str());
	return 0;
}
