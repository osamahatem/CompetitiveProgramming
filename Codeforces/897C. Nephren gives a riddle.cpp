/*
 * 897C. Nephren gives a riddle.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const string f0 =
		"What are you doing at the end of the world? Are you busy? Will you save us?";
const string a = "What are you doing while sending \"";
const string b = "\"? Are you busy? Will you send \"";
const string c = "\"?";
const long long lim = 1e18 + 5;

long long len[100];
int N;

char solve(int n, long long k) {
	if (!n)
		return k > f0.size() ? '.' : f0[k - 1];
	if (k <= a.size())
		return a[k - 1];
	k -= a.size();
	if (n >= N || k <= len[n - 1])
		return solve(n - 1, k);
	k -= len[n - 1];
	if (k <= b.size())
		return b[k - 1];
	k -= b.size();
	if (n >= N || k <= len[n - 1])
		return solve(n - 1, k);
	k -= len[n - 1];
	if (k <= c.size())
		return c[k - 1];
	return '.';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	len[0] = f0.size();
	for (N = 1; len[N - 1] <= lim; N++)
		len[N] = len[N - 1] * 2 + a.size() + b.size() + c.size();
	int q, n;
	long long k;
	cin >> q;
	while (q--) {
		cin >> n >> k;
		cout << solve(n, k);
	}
	cout << endl;
	return 0;
}
