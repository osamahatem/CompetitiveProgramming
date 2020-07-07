/*
 * 676E. The Last Fight Between Human and AI.cpp
 *
 *  Created on: May 25, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD1 = 1000003;
const int MOD2 = 1000033;

char coeff[100005][10];

int toInt(char arr[]) {
	bool sign = arr[0] == '-';
	int ret = 0;
	for (int i = sign; arr[i]; i++)
		ret = ret * 10 + arr[i] - '0';
	if (sign)
		ret *= -1;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k;
	bool fin = 1, turn = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; i++) {
		scanf("%s", coeff[i]);
		if (coeff[i][0] == '?')
			fin = 0;
		else
			turn = !turn;
	}
	if (!k)
		printf("%s\n",
				(coeff[0][0] == '0' || (coeff[0][0] == '?' && turn)) ?
						"Yes" : "No");
	else if (!fin)
		printf("%s\n", n % 2 ? "Yes" : "No");
	else {
		int last = 0;
		for (int i = 0; i < n; i++) {
			int c = toInt(coeff[i]);
			if ((last - c) % k) {
				printf("No\n");
				return 0;
			}
			last = (last - c) / k;
		}
		printf("%s\n", last == toInt(coeff[n]) ? "Yes" : "No");
	}
	return 0;
}
