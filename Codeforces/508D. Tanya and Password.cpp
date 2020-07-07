/*
 * 508D. Tanya and Password.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int graph[65][65][65], deg[65][65];
map<char, int> dic;
map<int, char> inv;
vector<int> ans;

void solve(int a, int b) {
	for (int i = 0; i < 62; i++)
		while (graph[a][b][i] != 0) {
			graph[a][b][i]--;
			solve(b, i);
			ans.push_back(i);
		}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int i = 0; i < 26; i++) {
		dic['a' + i] = i, dic['A' + i] = 26 + i;
		inv[i] = 'a' + i, inv[26 + i] = 'A' + i;
	}
	for (int i = 0; i < 10; i++)
		dic['0' + i] = 52 + i, inv[52 + i] = '0' + i;
	int n;
	string x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		int a = dic[x[0]], b = dic[x[1]], c = dic[x[2]];
		graph[a][b][c]++;
		deg[a][b]++, deg[b][c]--;
	}
	int s1 = dic[x[0]], s2 = dic[x[1]], cnts = 0, cnte = 0;
	for (int i = 0; i < 62; i++) {
		for (int j = 0; j < 62; j++) {
			if (deg[i][j] < -1 || deg[i][j] > 1) {
				cout << "NO" << endl;
				return 0;
			}
			if (deg[i][j] == 1)
				cnts++, s1 = i, s2 = j;
			if (deg[i][j] == -1)
				cnte++;
			if (cnts > 1 || cnte > 1) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	solve(s1, s2);
	ans.push_back(s2), ans.push_back(s1);
	if ((int) ans.size() != n + 2) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = (int) ans.size() - 1; i >= 0; i--)
		cout << inv[ans[i]];
	cout << endl;
	return 0;
}
