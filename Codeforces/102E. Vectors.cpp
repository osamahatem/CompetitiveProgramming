/*
 * 102E. Vectors.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool check(int x, int y, int xx, int yy, int a, int b) {
	if (!a && !b)
		return (x == xx && y == yy) ? true : false;
	long long num = 1ll * (xx - x) * b + 1ll * (y - yy) * a;
	long long den = 1ll * a * a + 1ll * b * b;
	if (num % den)
		return false;
	num /= den;
	if (a)
		return (-num * b + xx - x) % a ? false : true;
	return (num * a + yy - y) % b ? false : true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int x, y, xx, yy, a, b;
	cin >> x >> y >> xx >> yy >> a >> b;
	bool ans = false;
	for (int i = 0; i < 4; i++) {
		ans |= check(x, y, xx, yy, a, b);
		swap(x, y);
		y *= -1;
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
