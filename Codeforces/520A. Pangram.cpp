/*
 * 520A. Pangram.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, cnt = 0;
	string in;
	cin >> n >> in;
	for (int i = 0; i < n; i++)
		cnt += !vis[tolower(in[i]) - 'a'], vis[tolower(in[i]) - 'a'] = 1;
	cout << (cnt == 26 ? "YES" : "NO") << endl;
	return 0;
}
