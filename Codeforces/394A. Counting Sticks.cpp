/*
 * 394A. Counting Sticks.cpp
 *
 *  Created on: May 8, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

void output(int a, int b, int c) {
	while (a)
		cout << "|", a--;
	cout << "+";
	while (b)
		cout << "|", b--;
	cout << "=";
	while (c)
		cout << "|", c--;
	cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string in;
	cin >> in;
	int p = in.find('+', 0), e = in.find('=', 0);
	int a = p, b = e - p - 1, c = (int) in.size() - e - 1;
	if (a + b == c) {
		output(a, b, c);
		return 0;
	}
	if (a > 1 && a + b - 1 == c + 1) {
		output(a - 1, b, c + 1);
		return 0;
	}
	if (b > 1 && a + b - 1 == c + 1) {
		output(a, b - 1, c + 1);
		return 0;
	}
	if (c > 1 && a + b + 1 == c - 1) {
		output(a, b + 1, c - 1);
		return 0;
	}
	cout << "Impossible" << endl;
	return 0;
}
