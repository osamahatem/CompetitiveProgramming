/*
 * 123B. Squares.cpp
 *
 *  Created on: Aug 5, 2015
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

	int a, b, x1, y1, x2, y2;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	long long ty1 = y1 + x1, ty2 = y2 + x2;
	if (ty1 > 0)
		ty1 += 2 * a - 1;
	if (ty2 > 0)
		ty2 += 2 * a - 1;
	ty1 /= 2 * a, ty2 /= 2 * a;
	long long ans = abs(ty1 - ty2);
	ty1 = y1 - x1, ty2 = y2 - x2;
	if (ty1 > 0)
		ty1 += 2 * b - 1;
	if (ty2 > 0)
		ty2 += 2 * b - 1;
	ty1 /= 2 * b, ty2 /= 2 * b;
	ans = max(ans, abs(ty1 - ty2));
	cout << ans << endl;
	return 0;
}
