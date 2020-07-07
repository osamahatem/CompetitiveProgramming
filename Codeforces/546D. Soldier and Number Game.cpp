/*
 * 546D. Soldier and Number Game.cpp
 *
 *  Created on: May 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e6 + 5;

bool isComp[MAXN];
int sumFacts[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int i = 2; i < MAXN; i++) {
		if (!isComp[i]) {
			for (int j = i * 2; j < MAXN; j += i) {
				isComp[j] = 1;
				int temp = j;
				while (temp % i == 0) {
					sumFacts[j]++;
					temp /= i;
				}
			}
		}
	}
	for (int i = 2; i < MAXN; i++) {
		if (!isComp[i])
			sumFacts[i]++;
		sumFacts[i] += sumFacts[i - 1];
	}

	int t, a, b;
	cin >> t;
	while (t--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", sumFacts[a] - sumFacts[b]);
	}
	return 0;
}
