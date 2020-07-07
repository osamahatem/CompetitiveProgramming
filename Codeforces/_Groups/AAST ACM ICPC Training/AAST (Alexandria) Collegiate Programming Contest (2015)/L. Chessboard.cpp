/*
 * L. Chessboard.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1000001;

vector<int> factors[MAXN];
int firstFactor[MAXN];
bool prime[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("chess.in", "r", stdin);
	for (int i = 2; i < MAXN; i++)
		if (!prime[i])
			for (int j = i; j < MAXN; j += i)
				prime[j] = 1, firstFactor[j] = i;
	for (int i = 2; i < MAXN; i++) {
		int temp = i;
		while (temp > 1) {
			factors[i].push_back(firstFactor[temp]);
			temp /= firstFactor[temp];
		}
	}
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		n *= n;
		map<int, int> ans;
		for (int i = 0; i < 32; i++)
			for (int j = 0; j < (int) factors[n - i].size(); j++)
				ans[factors[n - i][j]]++;
		ans[2] -= 20, ans[3] -= 4, ans[5] -= 2, ans[7] -= 2;
		for (auto it = ans.begin(); it != ans.end(); it++)
			cout << it->first << " " << it->second << endl;
	}
	return 0;
}
