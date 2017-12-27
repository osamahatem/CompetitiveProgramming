/*
 * 909F. AND-permutations.cpp
 *
 *  Created on: Dec 27, 2017
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/56666
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int sol6[] = { 0, 3, 6, 2, 5, 1, 4 };
const int sol7[] = { 0, 7, 3, 6, 5, 1, 2, 4 };

int arr[MAXN];

bool solve1(int n) {
	if (n & 1)
		return false;
	int p = 1;
	for (; p <= n; p <<= 1)
		;
	p >>= 1;
	for (; n; n = p + p - n - 2) {
		while (p > n)
			p >>= 1;
		for (int i = p, j = p - 1; i <= n; i++, j--)
			arr[i] = j, arr[j] = i;
	}
	return true;
}

bool solve2(int n) {
	if (n < 6 || !(n & (n - 1)))
		return false;
	if (n == 6) {
		for (int i = 1; i <= n; i++)
			arr[i] = sol6[i];
	} else {
		for (int i = 1; i <= 7; i++)
			arr[i] = sol7[i];
		for (int p = 8; p < n; p <<= 1) {
			for (int i = p; i < min(n, (p << 1) - 1); i++)
				arr[i] = i + 1;
			arr[min(n, (p << 1) - 1)] = p;
		}
	}
	return true;
}

void print(int n) {
	printf("YES\n");
	for (int i = 1; i <= n; i++) {
		if (i > 1)
			printf(" ");
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	if (!solve1(n))
		printf("NO\n");
	else
		print(n);
	if (!solve2(n))
		printf("NO\n");
	else
		print(n);
	return 0;
}
