/*
 * 490B. Queue.cpp
 *
 *  Created on: Nov 23, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, x, y, nxt[1000006];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	set<int> s1, s2;
	set<int>::iterator it;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		nxt[x] = y;
		s1.insert(x);
		s2.insert(y);
	}
	for (it = s2.begin(); it != s2.end(); it++)
		s1.erase(*it);
	int a = *s1.begin(), b = nxt[0];
	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		if (i % 2) {
			cout << b;
			b = nxt[b];
		} else {
			cout << a;
			a = nxt[a];
		}
	}
	cout << endl;
	return 0;
}
