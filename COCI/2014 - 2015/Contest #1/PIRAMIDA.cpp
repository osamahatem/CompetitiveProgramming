/*
 * PIRAMIDA.cpp
 *
 *  Created on: Oct 18, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct query {
	int id;
	char c;
	long long line, ans;

	static bool byChar(const query &a, const query &b) {
		if (a.c != b.c)
			return a.c < b.c;
		return a.id < b.id;
	}

	static bool byID(const query &a, const query &b) {
		return a.id < b.id;
	}
};

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long n, l;
	string in;
	int k;
	char c;
	cin >> n >> in >> k;
	long long len = (int) in.size();
	int* accum = new int[len + 1];
	vector<query> all;
	for (int i = 0; i < k; i++) {
		cin >> l >> c;
		all.push_back(query { i, c, l, 0 });
	}
	sort(all.begin(), all.end(), query::byChar);
	int cur = 0;
	for (int ch = 0; ch < 26; ch++) {
		accum[0] = 0;
		for (int i = 1; i <= len; i++)
			accum[i] = accum[i - 1] + (bool) (in[i - 1] == ch + 'A');
		while (cur < k && all[cur].c == ch + 'A') {
			l = all[cur].line;
			all[cur].ans += (l / len) * accum[len];
			long long end;
			if (l % 2)
				end = (l % len) * (((l + 1) / 2) % len) % len;
			else
				end = ((l / 2) % len) * ((l + 1) % len) % len;
			end = (end - 1 + len) % len;
			l %= len;
			long long start = end - l;
			all[cur].ans += accum[end + 1];
			if (start >= 0)
				all[cur].ans -= accum[start + 1];
			else {
				start += len;
				all[cur].ans += accum[len] - accum[start + 1];
			}
			cur++;
		}
	}
	sort(all.begin(), all.end(), query::byID);
	for (int i = 0; i < k; i++)
		cout << all[i].ans << endl;
	return 0;
}
