/*
 * 12319 - Edgetown's Traffic Jams.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 105;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, cost1[MAXN][MAXN], cost2[MAXN][MAXN];
	while (cin >> n, n) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				cost1[i][j] = cost2[i][j] = 1 << 20;
				if (i == j)
					cost1[i][j] = cost2[i][j] = 0;
			}
		string s;
		getline(cin, s);
		for (int i = 1; i <= n; i++) {
			getline(cin, s);
			stringstream ss;
			ss << s;
			int x;
			ss >> x;
			while (ss >> x)
				cost1[i][x] = 1;
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					cost1[i][j] = min(cost1[i][j], cost1[i][k] + cost1[k][j]);
		for (int i = 1; i <= n; i++) {
			getline(cin, s);
			stringstream ss;
			ss << s;
			int x;
			ss >> x;
			while (ss >> x)
				cost2[i][x] = 1;
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					cost2[i][j] = min(cost2[i][j], cost2[i][k] + cost2[k][j]);
		int a, b;
		cin >> a >> b;
		bool flag = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (cost1[i][j] * a + b < cost2[i][j])
					flag = 0;
		if (flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
