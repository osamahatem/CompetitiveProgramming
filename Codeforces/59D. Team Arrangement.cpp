/*
 * 59D. Team Arrangement.cpp
 *
 *  Created on: Aug 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;

int rnk[MAXN], team[MAXN];
vector<vector<int> > teams;

bool cmp(int a, int b) {
	return rnk[a] < rnk[b];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x, k;
	scanf("%d", &n);
	for (int i = 0; i < 3 * n; i++) {
		scanf("%d", &x);
		rnk[x] = i;
	}
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < 3; j++) {
			scanf("%d", &x);
			team[x] = i;
			temp.push_back(x);
		}
		sort(temp.begin(), temp.end(), cmp);
		teams.push_back(temp);
	}
	scanf("%d", &k);
	if (teams[team[k]][0] != k) {
		bool sp = 0;
		for (int i = 1; i <= 3 * n; i++) {
			if (i == k)
				continue;
			if (sp)
				printf(" ");
			printf("%d", i);
			sp = 1;
		}
	} else {
		vector<int> temp, temp2;
		temp.push_back(teams[team[k]][1]);
		temp.push_back(teams[team[k]][2]);
		int mm = max(teams[team[k]][1], teams[team[k]][2]);
		for (int i = 0; i < team[k]; i++)
			for (int j = 0; j < 3; j++)
				temp.push_back(teams[i][j]);
		sort(temp.begin(), temp.end());
		while (temp.back() > mm) {
			temp2.push_back(temp.back());
			temp.pop_back();
		}
		for (int i = 0; i < (int) temp.size(); i++) {
			if (i)
				printf(" ");
			printf("%d", temp[i]);
		}
		for (int i = team[k] + 1; i < n; i++)
			for (int j = 0; j < 3; j++)
				temp2.push_back(teams[i][j]);
		sort(temp2.begin(), temp2.end());
		for (int i = 0; i < (int) temp2.size(); i++)
			printf(" %d", temp2[i]);
	}
	printf("\n");
	return 0;
}
