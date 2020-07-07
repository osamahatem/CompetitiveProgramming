/*
 * 230B. T-primes.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

bool isComp[MAXN];
vector<long long> primes;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int i = 2; i < MAXN; i++)
		if (!isComp[i]) {
			primes.push_back(i);
			for (long long j = (long long) i * i; j < MAXN; j += i)
				isComp[j] = 1;
		}
	for (int i = 0; i < (int) primes.size(); i++)
		primes[i] *= primes[i];
	int n;
	long long m;
	cin >> n;
	while (n--) {
		cin >> m;
		if (binary_search(primes.begin(), primes.end(), m))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
