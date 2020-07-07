/*
 * 6396 - Factors.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int prime[] =
		{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53 };
map<long long, long long> mem;

void pre(int idx, int cnt, int last, long long num, long long ans) {
	if (cnt && mem.count(ans))
		mem[ans] = min(num, mem[ans]);
	else if (cnt)
		mem[ans] = num;
	long long fact = 1, cur = 1;
	for (int i = 1; i <= last; i++) {
		if (cur > LLONG_MAX / prime[idx] || fact > LLONG_MAX / ((i + cnt) / i))
			break;
		fact *= i + cnt;
		fact /= i;
		cur *= prime[idx];
		if (num > LLONG_MAX / cur || ans > LLONG_MAX / fact)
			break;
		pre(idx + 1, cnt + i, i, num * cur, ans * fact);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	pre(0, 0, 62, 1, 1);
	long long n;
	while (cin >> n)
		cout << n << " " << mem[n] << endl;
	return 0;
}
