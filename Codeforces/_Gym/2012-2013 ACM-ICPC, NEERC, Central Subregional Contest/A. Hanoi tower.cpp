/*
 * A. Hanoi tower.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int len;
char s[255];

bool solve(int n, char src, char dest, char piv) {
	if (n < 0)
		return true;
	if (s[n] == src)
		return solve(n - 1, src, piv, dest);
	if (s[n] == dest)
		return solve(n - 1, piv, dest, src);
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%s", &len, s);
	printf("%s\n", solve(len - 1, 'A', 'B', 'C') ? "YES" : "NO");
	return 0;
}
