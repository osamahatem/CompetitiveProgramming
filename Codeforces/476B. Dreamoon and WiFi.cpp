/*
 * 476B. Dreamoon and WiFi.cpp
 *
 *  Created on: Jun 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string snd, rec;
int ans, fin;

void solve(int idx, int pos) {
	if (idx == (int) rec.size()) {
		ans += pos == fin;
		return;
	}
	if (rec[idx] != '?')
		solve(idx + 1, pos + (rec[idx] == '-' ? -1 : +1));
	else
		solve(idx + 1, pos - 1), solve(idx + 1, pos + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> snd >> rec;
	for (int i = 0; i < (int) snd.size(); i++)
		fin += snd[i] == '+' ? 1 : -1;
	solve(0, 0);
	int cnt = 0;
	for (int i = 0; i < (int) rec.size(); i++)
		cnt += rec[i] == '?';
	cnt = 1 << cnt;
	cout << fixed << setprecision(9) << 1.0 * ans / cnt << endl;
	return 0;
}
