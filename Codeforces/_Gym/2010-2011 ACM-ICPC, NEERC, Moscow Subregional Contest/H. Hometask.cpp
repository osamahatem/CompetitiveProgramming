/*
 * H. Hometask.cpp
 *
 *  Created on: Oct 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

bool vis[MAXN];
vector<int> primes;

int cnt(int n, int p) {
	int ret = 0;
	while (n) {
		ret += n / p;
		n /= p;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int i = 2; i < MAXN; i++) {
		if (!vis[i]) {
			primes.push_back(i);
			for (int j = i + i; j < MAXN; j += i)
				vis[j] = 1;
		}
	}
	int n;
	cin >> n;
	int x = n;
	bool ans = true;
	for (int i = 0; primes[i] <= n / primes[i]; i++) {
		if (n % primes[i] == 0) {
			int c = 0;
			while (n % primes[i] == 0) {
				n /= primes[i];
				c++;
			}
			if (cnt(x - 1, primes[i]) < c)
				ans = false;
		}
	}
	if (n > 1 && !cnt(x - 1, n))
		ans = false;
	printf("%s\n", ans ? "YES" : "NO");
	return 0;
}
