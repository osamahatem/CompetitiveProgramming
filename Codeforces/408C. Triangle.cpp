/*
 * 408C. Triangle.cpp
 *
 *  Created on: Dec 15, 2017
 *      Author: Osama Hatem
 */
 
/*
Try all the possible valid placements of one side, and calculate the coordinates
of the third vertex: if it is valid according to the problem constraints, then
this is a valid answer, print it.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int a, b;

bool check(int xx, int yy) {
	int x = yy, y = xx;
	x *= -1;
	x *= b, y *= b;
	if (x % a || y % a)
		return false;
	x /= a, y /= a;
	return y != yy;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> a >> b;
	if (a > b)
		swap(a, b);
	bool valid = false;
	int x = -1, y = -1;
	for (int i = 1; !valid && i <= a; i++)
		for (int j = 1; !valid && j <= a; j++)
			if (i * i + j * j == a * a && check(i, j))
				valid = true, x = i, y = j;
	if (!valid) {
		cout << "NO" << endl;
		return 0;
	}
	int xx = -y * b / a, yy = x * b / a;
	cout << "YES\n0 0\n" << x << " " << y << "\n" << xx << " " << yy << endl;
	return 0;
}
