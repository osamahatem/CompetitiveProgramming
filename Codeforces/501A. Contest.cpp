/*
 * 501A. Contest.cpp
 *
 *  Created on: Jun 7, 2015
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

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int p1 = max(3 * a / 10, a - a * c / 250);
	int p2 = max(3 * b / 10, b - b * d / 250);
	cout << (p1 > p2 ? "Misha" : (p1 < p2 ? "Vasya" : "Tie")) << endl;
	return 0;
}
