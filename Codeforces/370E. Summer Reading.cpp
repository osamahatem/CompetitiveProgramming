/*
 * 370E. Summer Reading.cpp
 *
 *  Created on: Aug 9, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, book[200000], prv[200000], dp[200000][6];

bool valid(int x, int cx, int y, int cy) {
	int zeroes = y - x - cy;
	int cnt = book[y] - book[x] - 1;
	if (zeroes >= 2 * cnt + (cx == 1) && zeroes <= 5 * (cnt + 1) - cx)
		return true;
	return false;
}

void fill(int x, int cx, int y, int cy) {
	int cnt = book[y] - book[x] - 1;
	if (cx == 1) {
		book[x + 1] = book[x];
		cx++, x++;
	}
	x++;
	while (cy > 1) {
		book[y - 1] = book[y];
		y--, cy--;
	}
	y--;
	if (!cnt) {
		while (x <= y) {
			book[x] = book[x - 1];
			x++;
		}
		return;
	}
	int zeroes = y - x + 1;
	int rep = min(5, zeroes / cnt);
	int ex = zeroes - rep * cnt;
	while (cx < 5 && ex) {
		book[x] = book[x - 1];
		cx++, x++, ex--;
	}
	for (int i = x; i <= y; i += rep) {
		for (int j = 0; j < rep; j++)
			book[i + j] = book[i - 1] + 1;
		if (ex) {
			book[i + rep] = book[i - 1] + 1;
			ex--, i++;
		}
	}
}

int solve(int idx, int cnt) {
	if (!idx)
		return cnt == 1 && book[idx] == 1;
	int &ret = dp[idx][cnt];
	if (ret != -1)
		return ret;
	if (prv[idx] == idx - 1) {
		if (book[idx - 1] != book[idx]
				&& (cnt != 1 || book[idx - 1] + 1 != book[idx]))
			return ret = 0;
		if (book[idx - 1] == book[idx] && cnt == 1)
			return ret = 0;
		if (book[idx - 1] != book[idx]) {
			for (int i = 5; i > 1; i--)
				if (solve(idx - 1, i))
					return ret = 1;
		} else
			return ret = solve(idx - 1, cnt - 1);
	} else
		for (int i = 5; i; i--)
			if (valid(prv[idx], i, idx, cnt) && solve(prv[idx], i)) {
				fill(prv[idx], i, idx, cnt);
				return ret = 1;
			}
	return ret = 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &book[i]);

	if (!book[0])
		book[0] = 1;

	int last = 0;
	for (int i = 1; i < n; i++) {
		if (book[last] == book[i])
			for (int j = last + 1; j < i; j++)
				book[j] = book[i];
		if (book[i])
			last = i;
	}

	last = 0;
	for (int i = 1; i < n; i++) {
		prv[i] = last;
		if (book[i])
			last = i;
	}

	memset(dp, -1, sizeof dp);
	int flag = 0;
	int left = n - last - 1;
	for (int i = 5 - (left == 1); i > (last == n - 1); i--)
		if (solve(last, i)) {
			flag = i;
			break;
		}
	if (!flag) {
		printf("-1\n");
		return 0;
	}
	if (left == 1 || flag == 1) {
		book[last + 1] = book[last];
		last++;
	}
	for (int i = last + 1; i + 1 < n; i += 2)
		book[i] = book[i + 1] = book[i - 1] + 1;
	if (!book[n - 1])
		book[n - 1] = book[n - 2];
	printf("%d\n%d", book[n - 1], book[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", book[i]);
	printf("\n");
	return 0;
}
