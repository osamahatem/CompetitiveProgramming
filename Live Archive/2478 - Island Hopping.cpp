/*
 * 2478 - Island Hopping.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

struct node {
	double cur, maxi;
	int id;

	const bool operator <(const node &x) const {
		if (abs(cur - x.cur) > EPS)
			return cur < x.cur;
		if (abs(maxi - x.maxi) > EPS)
			return maxi < x.maxi;
		return id < x.id;
	}
};

int n;
long long x[55], y[55], m[55];
double dist[55][55];
bool vis[55];

double getDist(int i, int j) {
	long long dx = x[i] - x[j], dy = y[i] - y[j];
	return sqrt(dx * dx + dy * dy);
}

double prim() {
	double ans = 0.0;
	long long tot = 0;
	set<node> S;
	S.insert( { 0.0, 0.0, 0 });
	while (S.size()) {
		node cur = *S.begin();
		S.erase(S.begin());
		if (vis[cur.id])
			continue;
		vis[cur.id] = 1;
		ans += cur.maxi * m[cur.id];
		tot += m[cur.id];
		for (int i = 0; i < n; i++) {
			if (vis[i])
				continue;
			S.insert( { dist[cur.id][i], max(cur.maxi, dist[cur.id][i]), i });
		}
	}
	return ans / tot;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T = 0;
	while (scanf("%d", &n), n) {
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; i++)
			scanf("%lld%lld%lld", &x[i], &y[i], &m[i]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = getDist(i, j);
		printf("Island Group: %d Average %.2f\n\n", ++T, prim());
	}
	return 0;
}
