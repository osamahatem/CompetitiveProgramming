/*
 * 3B. Little Brackets.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct bigInt {
	string num;

	bigInt() {
	}

	bigInt(int n) {
		num = "";
		do {
			num += (n % 10) + '0';
			n /= 10;
		} while (n);
	}

	bigInt(string num) :
			num(num) {
	}

	const bigInt operator +(const bigInt &a) const {
		int i = 0, c = 0, x, y, s;
		string ret = "";
		while (i < (int) num.size() || i < (int) a.num.size()) {
			x = (i < (int) num.size()) ? num[i] - '0' : 0;
			y = (i < (int) a.num.size()) ? a.num[i] - '0' : 0;
			s = x + y + c;
			ret += (s % 10) + '0';
			c = s / 10;
			i++;
		}
		if (c)
			ret += c + '0';
		return bigInt(ret);
	}

	const bigInt operator +=(const bigInt &a) {
		*this = *this + a;
		return *this;
	}
};

ostream& operator <<(ostream& os, const bigInt &a) {
	string temp = a.num;
	reverse(temp.begin(), temp.end());
	os << temp;
	return os;
}

bigInt dp[55][55][55][2];
bool vis[55][55][55][2];

bigInt solve(int op, int cl, int k, bool r) {
	if (op + cl == 0) {
		if (r)
			return bigInt(1);
		return bigInt(0);
	}
	if (vis[op][cl][k][r])
		return dp[op][cl][k][r];
	vis[op][cl][k][r] = 1;
	bigInt ret = bigInt(0);
	if (!k)
		r = 1;
	if (op && k)
		ret += solve(op - 1, cl + 1, k - 1, r);
	if (cl)
		ret += solve(op, cl - 1, k + 1, r);
	return dp[op][cl][k][r] = ret;
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
//#endif

	int n, k, tc = 0;
	while (cin >> n >> k, n) {
		if (tc)
			cout << endl;
		cout << "Case " << ++tc << ": " << solve(n, 0, k, 0) << endl;
	}
	return 0;
}
