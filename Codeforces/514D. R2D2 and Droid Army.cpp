/*
 * 514D. R2D2 and Droid Army.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int arr[MAXN][5];
deque<pair<int, int> > Q[5];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	int s = 0, e = -1, maxLen = 0, ans[5] = { 0, 0, 0, 0, 0 };
	while (e < N) {
		if (s > e) {
			e = s;
			for (int i = 0; i < M; i++) {
				while (Q[i].size())
					Q[i].pop_front();
				Q[i].push_back(make_pair(arr[s][i], s));
			}
		}
		for (int i = 0; i < M; i++)
			while (Q[i].size() && Q[i].front().second < s)
				Q[i].pop_front();
		for (int i = 0; i < M; i++) {
			while (Q[i].size() && Q[i].back().first < arr[e][i])
				Q[i].pop_back();
			Q[i].push_back(make_pair(arr[e][i], e));
		}
		int temp = 0;
		for (int i = 0; i < M; i++)
			temp += Q[i].front().first;
		if (temp <= K) {
			if (e - s + 1 > maxLen) {
				maxLen = e - s + 1;
				for (int i = 0; i < M; i++)
					ans[i] = Q[i].front().first;
			}
			e++;
		} else
			s++;
	}
	for (int i = 0; i < M; i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
