/*
 * 528A. Glass Carving.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int w, h, n, x;
	char t;
	set<int> Vs, Hs;
	multiset<int> Hlen, Vlen;
	set<int>::iterator it, it2;
	cin >> w >> h >> n;
	Vs.insert(0), Hs.insert(0);
	Hlen.insert(h), Vlen.insert(w);
	while (n--) {
		cin >> t >> x;
		if (t == 'H') {
			it = --Hs.upper_bound(x);
			it2 = ++it, it--;
			int len, s, e;
			if (it2 == Hs.end())
				e = h;
			else
				e = *it2;
			s = *it, len = e - s;
			Hs.insert(x);
			Hlen.erase(Hlen.lower_bound(len));
			Hlen.insert(x - s), Hlen.insert(e - x);
		} else {
			it = --Vs.upper_bound(x);
			it2 = ++it, it--;
			int len, s, e;
			if (it2 == Vs.end())
				e = w;
			else
				e = *it2;
			s = *it, len = e - s;
			Vs.insert(x);
			Vlen.erase(Vlen.lower_bound(len));
			Vlen.insert(x - s), Vlen.insert(e - x);
		}
		cout << (long long) (*--Vlen.end()) * (*--Hlen.end()) << endl;
	}
	return 0;
}
