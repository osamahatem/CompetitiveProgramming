/*
 * 526C. Om Nom and Candies.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//  freopen("out.out", "w", stdout);
#endif

	int c, hr, hb, wr, wb;
	long long ans = 0;
	cin >> c >> hr >> hb >> wr >> wb;
	if (wr < wb)
		swap(wr, wb), swap(hr, hb);
	if (wr > c / wr) {
		for (int i = 0; i <= c / wr; i++) {
			long long temp = (long long) i * hr;
			int cb = (c - i * wr) / wb;
			temp += (long long) cb * hb;
			ans = max(ans, temp);
		}
	} else {
		if ((long long) wr * hb > (long long) wb * hr)
			swap(wr, wb), swap(hr, hb);
		for (int i = 0; i < wr; i++) {
			long long temp = (long long) i * hb;
			int cr = (c - i * wb) / wr;
			temp += (long long) cr * hr;
			ans = max(ans, temp);
		}
	}
	cout << ans << endl;
	return 0;
}
