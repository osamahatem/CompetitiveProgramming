/*
 * 478B. Random Teams.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long n, m, mini = 0, maxi;
	cin >> n >> m;
	n -= m;
	long long div = n / m, mod = n % m;
	maxi = n * (n + 1) / 2;
	mini += (m - mod) * (div * (div + 1) / 2);
	div++;
	mini += mod * (div * (div + 1) / 2);
	cout << mini << " " << maxi << endl;
	return 0;
}
