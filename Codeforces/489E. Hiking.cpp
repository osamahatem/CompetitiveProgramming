/*
 * 489E. Hiking.cpp
 *
 *  Created on: Jun 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;
const int MAXN = 1005;

int N, L, pos[MAXN], pic[MAXN], den[MAXN], prv[MAXN];
double best[MAXN], dist[MAXN];

bool check(double rat) {
	fill(dist, dist + N + 1, 1e18);
	dist[0] = 0.0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j <= N; j++)
			if (dist[i] + sqrt(fabs(pos[j] - pos[i] - L)) - rat * pic[j]
					< dist[j]) {
				dist[j] = dist[i] + sqrt(fabs(pos[j] - pos[i] - L))
						- rat * pic[j];
				prv[j] = i;
			}
	return dist[N] > 0.0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> N >> L;
	for (int i = 1; i <= N; i++)
		cin >> pos[i] >> pic[i];
	double s = 0.0, e = 1e18;
	for (double sz = (e - s) / 2.0; sz > EPS; sz *= 0.5)
		if (check(s + sz))
			s += sz;
	vector<int> ans;
	ans.push_back(N);
	while (prv[N]) {
		ans.push_back(prv[N]);
		N = prv[N];
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
