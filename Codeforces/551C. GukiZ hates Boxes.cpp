/*
 * 551C. GukiZ hates Boxes.cpp
 *
 *  Created on: Jun 13, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, box[MAXN], temp[MAXN];

bool valid(long long t) {
	long long sum = 0, tt = t;
	int nn = 0, mm = 0, p = -1;
	for (int i = 0; i < n; i++)
		sum += temp[i] = box[i];
	while (sum && mm < m) {
		if (tt <= 0) {
			tt = t;
			p = -1;
			mm++;
		} else if (temp[nn] == 0) {
			nn++;
		} else if (p < nn) {
			tt -= nn - p;
			p = nn;
		} else {
			int val = min((long long) temp[nn], tt);
			tt -= val;
			temp[nn] -= val;
			sum -= val;
		}
	}
	return !sum;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> box[i];
	long long s = 0, e = 1ll << 60;
	while (s < e) {
		long long mid = s + (e - s) / 2;
		if (valid(mid))
			e = mid;
		else
			s = mid + 1;
	}
	cout << e << endl;
	return 0;
}
