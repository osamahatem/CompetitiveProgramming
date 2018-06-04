/*
 * 439E. Devu and Birthday Celebration.cpp
 *
 *  Created on: Jun 4, 2018
 *      Author: Osama Hatem
 */

/*
 * First, we count all possible partitions of n sweets over f friends. Each
 * friend needs at least 1 sweet, so we give each 1, and then calculate the
 * number of ways of partitioning the remaining n - f over f slots. This is
 * equivalent to (n - 1) choose (f - 1).
 * Now, we need to exclude all partitions that have a gcd > 1. There are two
 * observations here:
 * 	1.	The only possible values for the gcd are n's divisors.
 * 	2.	We can only consider prime factors, as they will inherently generate
 * 		other divisors.
 * We use inclusion-exclusion technique to count partitions with different prime
 * factors combinations, and to remove duplicates, then we subtract that from
 * the total number of partitions calculated at the beginning, leaving us with
 * only partitions having gcd = 1.
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

long long fact[MAXN], ifact[MAXN];
int primes[MAXN];
vector<int> factors;

long long fast_pow(long long b, int p = MOD - 2) {
	long long ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % MOD;
		b = b * b % MOD;
	}
	return ret;
}

void init() {
	fact[0] = ifact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		ifact[i] = fast_pow(fact[i]);
	}

	memset(primes, -1, sizeof primes);
	for (int i = 2; i < MAXN; i++)
		if (primes[i] == -1)
			for (int j = i; j < MAXN; j += i)
				primes[j] = i;
}

long long nCr(int n, int r) {
	return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	init();

	int q;
	cin >> q;
	while (q--) {
		int n, f;
		cin >> n >> f;

		factors.clear();
		int nn = n;
		while (nn > 1) {
			int p = primes[nn];
			while (nn % p == 0)
				nn /= p;
			factors.push_back(p);
		}

		long long ans = nCr(n - 1, f - 1);
		nn = factors.size();
		for (int i = 1; i < (1 << nn); i++) {
			int d = 1, cnt = 0;
			for (int j = 0; j < (int) factors.size(); j++)
				if ((i >> j) & 1)
					d *= factors[j], cnt++;

			if (1ll * d * f > n)
				continue;

			long long temp = nCr((n - d * f) / d + f - 1, f - 1);
			if (cnt & 1)
				temp = MOD - temp;
			ans = (ans + temp) % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
