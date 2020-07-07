/*
 ID: 19semse1
 PROG: pprime
 LANG: C++
 */
/*
 * pprime.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

set<int> ans;
int a, b;

bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int toInt(string x) {
	int ret = 0;
	for (int i = 0; i < (int) x.size(); i++)
		ret = ret * 10 + x[i] - '0';
	return ret;
}

void solve(string cur) {
	if (cur.size() > 9)
		return;
	int curN = toInt(cur);
	if (curN > b)
		return;
	if (curN >= a && isPrime(curN))
		ans.insert(curN);
	for (char i = '0'; i <= '9'; i++) {
		string temp = cur + i;
		reverse(temp.begin(), temp.end());
		temp += i;
		solve(temp);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
#endif

	cin >> a >> b;
	for (char i = '0'; i <= '9'; i++) {
		string temp;
		temp += i;
		solve(temp);
		temp += i;
		solve(temp);
	}
	for (set<int>::iterator it = ans.begin(); it != ans.end(); it++)
		cout << *it << endl;
	return 0;
}
