/*
 * F. Killer Exam.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[100005];

bool check(long long x, long long n, int r) {
	long long temp = 1;
	while (r-- && temp <= n / x)
		temp *= x;
	return r == -1;
}

long long getRoot(long long n, int r) {
	long long s = 1, e = n;
	while (s < e) {
		long long m = (s + e + 1) / 2;
		if (check(m, n, r))
			s = m;
		else
			e = m - 1;
	}
	return s;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

//	freopen("killer.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		vector<pair<int, bool>> grps;
		scanf("%s", in);
		int x = 0;
		long long q = 0, ans = -1;
		int ansR = 0;
		for (int i = 0; in[i]; i++) {
			if (in[i] >= '0' && in[i] <= '9')
				x = x * 10 + in[i] - '0';
			else {
				grps.push_back(make_pair(x, in[i] == 'T'));
				q += x;
				x = 0;
			}
		}
		long long last = 0;
		for (int r = 1; r < 60; r++) {
			long long root = getRoot(q, r);
			if (root == last)
				continue;
			last = root;
			long long left = 0, tmpAns = 0;
			bool tf = 0;
			vector<pair<int, bool>> temp = grps;
			for (int i = 0; i < (int) grps.size(); i++) {
				if (!temp[i].first)
					continue;
				if (left) {
					long long x = min(1ll * temp[i].first, left);
					tmpAns += x * (tf == temp[i].second ? 1 : 0);
					left -= x, temp[i].first -= x;
					if (!left)
						tf = !tf;
					i--;
				} else if (root > temp[i].first) {
					tmpAns += temp[i].first * (tf == temp[i].second ? 1 : 0);
					left = root - temp[i].first;
				} else {
					int x = temp[i].first / root;
					tmpAns += x / 2 * root;
					if (tf == temp[i].second && (x & 1))
						tmpAns += root;
					tf ^= (x & 1);
					temp[i].first -= x * root;
					i--;
				}
			}
			if (tmpAns > ans)
				ans = tmpAns, ansR = r;
			tmpAns = q - tmpAns;
			if (tmpAns > ans)
				ans = tmpAns, ansR = r;
		}
		printf("%d\n", ansR);
	}
	return 0;
}
