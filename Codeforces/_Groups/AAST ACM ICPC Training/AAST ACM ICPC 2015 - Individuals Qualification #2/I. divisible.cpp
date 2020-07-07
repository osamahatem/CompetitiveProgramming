/*
 * I. divisible.cpp
 *
 *  Created on: Sep 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[10][100000];
pair<int, int> par[10][100000];
int n, len;

bool check(long long x) {
	int last = 9;
	while (x) {
		if (x % 10 > last)
			return false;
		last = x % 10;
		x /= 10;
	}
	return true;
}

int bfs() {
	memset(vis, 0, sizeof vis);
	int ln = 0;
	queue<int> Q;
	for (int i = 1; i < 10; i++) {
		Q.push(i);
		Q.push(i);
		vis[i][i] = 1;
		par[i][i] = make_pair(0, 0);
	}
	while (Q.size()) {
		ln++;
		int sz = Q.size() / 2;
		while (sz--) {
			int last = Q.front();
			Q.pop();
			int mod = Q.front();
			Q.pop();
			if (!mod && ln > len)
				return last;
			for (int i = last; i < 10; i++) {
				int nm = (mod * 10 + i) % n;
				if (!vis[i][nm]) {
					Q.push(i);
					Q.push(nm);
					vis[i][nm] = 1;
					par[i][nm] = make_pair(last, mod);
				}
			}
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("divisible.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case " << t << ": ";
		int temp;
		cin >> n;
		len = 0, temp = n;
		while (temp)
			len++, temp /= 10;
		temp = -1;
		for (int i = 2; i < 10; i++) {
			if (check(n * i)) {
				temp = n * i;
				break;
			}
		}
		if (temp != -1)
			cout << temp << endl;
		else {
			int ans = bfs();
			if (ans == -1)
				cout << "-1" << endl;
			else {
				string out;
				int mod = 0;
				while (ans) {
					out += '0' + ans;
					int pans = par[ans][mod].first, pmod = par[ans][mod].second;
					ans = pans, mod = pmod;
				}
				reverse(out.begin(), out.end());
				cout << out << endl;
			}
		}
	}
	return 0;
}
