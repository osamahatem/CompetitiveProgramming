/*
 * 364C. Beautiful Set.cpp
 *
 *  Created on: Aug 2, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5001;

int k;
bool vis[MAXN];
vector<int> primes;
vector<pair<int, int>> ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int i = 2; i < MAXN; i++)
		if (!vis[i]) {
			primes.push_back(i);
			for (int j = i * i; j < MAXN; j += i)
				vis[j] = 1;
		}
	cin >> k;
	ans.push_back(make_pair(0, 1));
	for (int i = 0; (int) ans.size() < k; i++) {
		int sz = (int) ans.size();
		for (int pw = primes[i]; pw <= 2 * k * k; pw *= primes[i]) {
			for (int j = 0; j < sz; j++)
				if (ans[j].second <= 2 * k * k / pw)
					ans.push_back(
							make_pair(ans[j].first + 1, ans[j].second * pw));
		}
	}
	sort(ans.begin(), ans.end(), greater<pair<int, int>>());
	for (int i = 0; i < k; i++) {
		if (i)
			printf(" ");
		printf("%d", ans[i].second);
	}
	printf("\n");
	return 0;
}
