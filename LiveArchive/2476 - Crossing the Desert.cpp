/*
 * 2476 - Crossing the Desert.cpp
 *
 *  Created on: Dec 17, 2017
 *      Author: Osama Hatem
 */
 
/*
We use Dijkstra's to compute the least amount of food needed at each node. The
starting state is the last node with 0 food required upon arrival. For each edge
we either can bring all the required food in one go, or we have to simulate
going back and forth, bringing a small amount of extra food each time, until the
requirements are met.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;
const double LIM = 1e6;

int n, cap, x[22], y[22];
double cost[22][22];
bool vis[22];

double solve() {
	memset(vis, 0, sizeof vis);
	set<pair<double, int>> S;
	S.insert(make_pair(0.0, n - 1));
	while (S.size()) {
		double food = S.begin()->first;
		int id = S.begin()->second;
		S.erase(S.begin());
		if (vis[id])
			continue;
		vis[id] = 1;
		if (id == 0 || food > LIM + EPS)
			return food;
		for (int i = 0; i < n; i++) {
			double c = cost[id][i];
			if ((double) cap > food + 2.0 * c - EPS) {
				S.insert(make_pair(food + c, i));
			} else if ((double) cap > 3.0 * c + EPS) {
				double extra = (double) cap - 3.0 * c;
				double tf = food, nf = 0.0;
				while ((double) cap - 2.0 * c < tf - EPS) {
					nf += 2.0 * c + extra;
					tf -= extra;
				}
				nf += c + tf;
				S.insert(make_pair(nf, i));
			}
		}
	}
	return LIM + LIM;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed << setprecision(0);
	int t = 0;
	while (cin >> n >> cap, n) {
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cost[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
		double ans = solve();
		cout << "Trial " << ++t << ": ";
		if (ans > LIM + EPS)
			cout << "Impossible" << endl << endl;
		else
			cout << ceil(ans - EPS) << " units of food" << endl << endl;
	}
	return 0;
}
