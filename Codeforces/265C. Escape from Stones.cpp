/*
 * 265C. Escape from Stones.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

int ans[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string in;
	cin >> in;
	int N = in.size();
	int s = 0, e = N - 1;
	for (int i = 0; i < N; i++)
		if (in[i] == 'l')
			ans[e--] = i + 1;
		else
			ans[s++] = i + 1;
	for (int i = 0; i < N; i++)
		cout << ans[i] << "\n";
	return 0;
}
