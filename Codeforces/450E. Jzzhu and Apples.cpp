/*
 * 450E. Jzzhu and Apples.cpp
 *
 *  Created on: Jul 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> primes;
bool sieve[MAXN], used[MAXN];

void doSieve() {
	for (int i = 2; i <= MAXN / 2; i++)
		if (!sieve[i]) {
			primes.push_back(i);
			for (int j = 2 * i; j <= MAXN / 2; j += i)
				sieve[j] = 1;
		}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	doSieve();
	int n;
	cin >> n;
	vector<int> ans, even;
	for (int i = 1; i < (int) primes.size() && primes[i] <= n / 2; i++) {
		int cnt = 1;
		ans.push_back(primes[i]), used[primes[i]] = 1;
		for (int j = 3 * primes[i]; j <= n; j += primes[i])
			if (!used[j])
				ans.push_back(j), cnt++, used[j] = 1;
		if (cnt % 2)
			ans.push_back(2 * primes[i]), used[2 * primes[i]] = 1;
		else
			even.push_back(2 * primes[i]);
		if (even.size() == 2) {
			ans.push_back(even[0]), ans.push_back(even[1]);
			used[even[0]] = used[even[1]] = 1;
			even.clear();
		}
	}
	for (int i = 2; i <= n; i += 2) {
		if (!used[i])
			even.push_back(i);
		if (even.size() == 2) {
			ans.push_back(even[0]), ans.push_back(even[1]);
			used[even[0]] = used[even[1]] = 1;
			even.clear();
		}
	}
	cout << ans.size() / 2 << endl;
	for (int i = 0; i < (int) ans.size(); i += 2)
		cout << ans[i] << " " << ans[i + 1] << endl;
	return 0;
}
