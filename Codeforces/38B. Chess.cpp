/*
 * 38B. Chess.cpp
 *
 *  Created on: Apr 12, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int rowRook, colRook, rowKnight, colKnight;

bool valid(int r, int c) {
	if (r == rowRook || c == colRook)
		return false;
	if (r == rowKnight && c == colKnight)
		return false;
	for (int i = -2; i <= 2; i++)
		for (int j = -2; j <= 2; j++) {
			if (!i || !j || abs(i) == abs(j))
				continue;
			int nr = r + i, nc = c + j;
			if (nr < 1 || nc < 1 || nr > 8 || nc > 8)
				continue;
			if (nr == rowRook && nc == colRook)
				return false;
			if (nr == rowKnight && nc == colKnight)
				return false;
		}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	char inR[3], inN[3];
	scanf("%s%s", inR, inN);
	rowRook = inR[1] - '0', colRook = inR[0] - 'a' + 1;
	rowKnight = inN[1] - '0', colKnight = inN[0] - 'a' + 1;
	int ans = 0;
	for (int r = 1; r <= 8; r++)
		for (int c = 1; c <= 8; c++)
			ans += valid(r, c);
	printf("%d\n", ans);
	return 0;
}
