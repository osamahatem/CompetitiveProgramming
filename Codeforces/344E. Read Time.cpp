/*
 * 344E. Read Time.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const long long INF = 1ll << 60;

int n, m;
long long h[MAXN], p[MAXN];

bool check(long long T) {
	int curS = 0;
	for (int i = 0; curS < m && i < n; i++) {
		int curE;
		long long tt = 0;
		for (curE = curS; curE < m; curE++) {
			if (h[i] >= p[curE])
				tt = h[i] - p[curS];
			else if (h[i] <= p[curS])
				tt = p[curE] - h[i];
			else
				tt = p[curE] - p[curS] + min(p[curE] - h[i], h[i] - p[curS]);
			if (tt > T)
				break;
		}
		curS = curE;
	}
	return !(curS < m);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	for (int i = 0; i < m; i++)
		cin >> p[i];
	long long s = 0, e = INF, mid;
	while (s < e) {
		mid = (s + e) / 2;
		if (check(mid))
			e = mid;
		else
			s = mid + 1;
	}
	cout << s << endl;
	return 0;
}
