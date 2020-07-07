/*
 * 568A. Primes or Palindromes.cpp
 *
 *  Created on: Aug 10, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 12e5 + 5;

bool prime[MAXN];
int primes[MAXN], pals[MAXN];

bool check(int i) {
	int rev = 0, temp = i;
	while (temp) {
		rev = rev * 10 + temp % 10;
		temp /= 10;
	}
	return i == rev;
}

void init() {
	fill(prime, prime + MAXN, 1);
	prime[1] = 0, pals[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		if (prime[i])
			for (int j = i * 2; j < MAXN; j += i)
				prime[j] = 0;
		primes[i] = primes[i - 1] + prime[i];
		pals[i] = pals[i - 1] + check(i);
	}
}

bool cmp(int a1, int b1, int a2, int b2) {
	return (long long) a1 * b2 <= (long long) a2 * b1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	init();
	int p, q, ans = 1;
	cin >> p >> q;
	for (int i = 2; i < MAXN; i++)
		if (cmp(primes[i], pals[i], p, q))
			ans = i;
	cout << ans << endl;
	return 0;
}
