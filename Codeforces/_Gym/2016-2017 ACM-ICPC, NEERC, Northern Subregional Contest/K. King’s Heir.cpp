/*
 * K. King’s Heir.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int LIM = 18 * 365;

int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int toDays(int d, int m, int y) {
	m--;
	int ret = y * 365;
	for (int i = 0; i < m; i++)
		ret += days[i];
	ret += d;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	int d, m, y, n;
	scanf("%d%d%d", &d, &m, &y);
	int date = toDays(d, m, y);
	scanf("%d", &n);
	int mini = 3650000, id = -1;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &d, &m, &y);
		int temp = toDays(d, m, y);
		if (date - temp >= LIM && date - temp < mini)
			mini = date - temp, id = i;
	}
	printf("%d\n", id);
	return 0;
}
