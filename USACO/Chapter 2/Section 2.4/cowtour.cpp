/*
 ID: 19semse1
 PROG: cowtour
 LANG: C++
 */
/*
 * cowtour.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double INF = 1e9;

double dist[155][155], diam[155];
int x[155], y[155], id[155];

int main() {
//#ifndef ONLINE_JUDGE
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
//#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = INF;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i], dist[i][i] = 0.0, diam[i] = 0.0, id[i] = i;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < n; j++)
			if (temp[j] == '1')
				dist[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (dist[i][j] < INF)
				id[j] = min(i, id[j]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (dist[i][j] < INF)
				diam[id[i]] = max(diam[id[i]], dist[i][j]);
	double ans = INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] < INF)
				continue;
			double d = hypot(x[i] - x[j], y[i] - y[j]), temp = 0.0;
			for (int k = 0; k < n; k++)
				if (dist[i][k] < INF)
					temp = max(temp, dist[i][k]);
			d += temp, temp = 0.0;
			for (int k = 0; k < n; k++)
				if (dist[j][k] < INF)
					temp = max(temp, dist[j][k]);
			d += temp;
			d = max(d, max(diam[id[i]], diam[id[j]]));
			ans = min(ans, d);
		}
	}
	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}
