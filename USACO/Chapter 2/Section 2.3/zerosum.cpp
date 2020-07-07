/*
 ID: 19semse1
 PROG: zerosum
 LANG: C++
 */
/*
 * zerosum.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N;
char cur[8];

void check() {
	int ret = 0, temp = 0, pow = 1;
	string exp = "1";
	for (int i = 2; i <= N; i++) {
		exp += cur[i - 2];
		exp += (char) ('0' + i);
	}
	for (int i = (int) exp.size() - 1; i >= 0; i--) {
		if (exp[i] == ' ')
			continue;
		if (exp[i] == '-')
			ret -= temp, temp = 0, pow = 1;
		else if (exp[i] == '+')
			ret += temp, temp = 0, pow = 1;
		else
			temp += pow * (exp[i] - '0'), pow *= 10;
	}
	ret += temp;
	if (!ret)
		cout << exp << endl;
}

void solve(int dig) {
	if (dig == N - 1) {
		check();
		return;
	}
	cur[dig] = ' ';
	solve(dig + 1);
	cur[dig] = '+';
	solve(dig + 1);
	cur[dig] = '-';
	solve(dig + 1);
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
//#endif

	cin >> N;
	solve(0);
	return 0;
}
