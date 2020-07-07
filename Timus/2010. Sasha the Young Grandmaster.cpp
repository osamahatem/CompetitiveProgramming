/*
 * 2010. Sasha the Young Grandmaster.cpp
 *
 *  Created on: Aug 2, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };

bool check(int x, int y) {
	return (x > 0 && y > 0 && x <= n && y <= n);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int x, y;
	scanf("%d%d%d", &n, &x, &y);
	int king = 8;
	if (x == 1 || x == n)
		king -= 3;
	if (y == 1 || y == n)
		king -= 3;
	if ((x == 1 || x == n) && (y == 1 || y == n))
		king++;
	if (n == 1)
		king = 0;
	printf("King: %d\n", king);
	int knight = 0;
	for (int i = 0; i < 8; i++)
		knight += check(x + dx[i], y + dy[i]);
	printf("Knight: %d\n", knight);
	int bishop = 0, db[] = { 1, n };
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			bishop += min(abs(x - db[i]), abs(y - db[j]));
	printf("Bishop: %d\n", bishop);
	int rook = n * 2 - 2;
	printf("Rook: %d\nQueen: %d\n", rook, rook + bishop);
	return 0;
}
