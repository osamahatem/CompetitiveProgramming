/*
 * 518E. Arthur and Questions.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1 << 30;

bool missing[MAXN];
int arr[MAXN], low[MAXN], up[MAXN];
int tarr[MAXN], tlow[MAXN], tup[MAXN], tmissing[MAXN], sz;

int convert(string in) {
	int ret = 0;
	bool neg = 0;
	if (in[0] == '-')
		neg = 1;
	for (int i = neg; i < (int) in.size(); i++)
		ret = ret * 10 + (in[i] - '0');
	if (neg)
		ret *= -1;
	return ret;
}

void solve() {
	int last = -INF;
	for (int i = 0; i < sz; i++) {
		if (tmissing[i])
			tarr[i] = last + 1, tlow[i] = tarr[i];
		else
			tlow[i] = tup[i] = tarr[i];
		last = tarr[i];
	}
	last = INF;
	for (int i = sz - 1; i >= 0; i--) {
		if (tmissing[i])
			tarr[i] = last - 1, tup[i] = tarr[i];
		else
			tlow[i] = tup[i] = tarr[i];
		last = tarr[i];
	}
	for (int i = 0; i < sz; i++) {
		if (tmissing[i]) {
			int e = i;
			while (e < sz && tmissing[e])
				e++;
			e--;
			int m = (i + e + 1) / 2;
			tarr[m] = max(tlow[m], min(0, tup[m]));
			for (int j = m - 1; j >= 0 && tmissing[j]; j--)
				tarr[j] = tarr[j + 1] - 1;
			for (int j = m + 1; j < sz && tmissing[j]; j++)
				tarr[j] = tarr[j - 1] + 1;
			i = e;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k;
	string in;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> in;
		if (in == "?")
			missing[i] = 1;
		else
			arr[i] = convert(in);
	}
	for (int i = 0; i < k; i++) {
		sz = 0;
		for (int j = i; j < n; j += k)
			tarr[sz] = arr[j], tmissing[sz++] = missing[j];
		solve();
		for (int j = i; j < n; j += k)
			arr[j] = tarr[j / k], low[j] = tlow[j / k], up[j] = tup[j / k];
	}
	for (int i = 0; i + k < n; i++)
		if (arr[i] >= arr[i + k] || up[i] < low[i]) {
			cout << "Incorrect sequence" << endl;
			return 0;
		}
	cout << arr[0];
	for (int i = 1; i < n; i++)
		cout << " " << arr[i];
	cout << endl;
	return 0;
}
