/*
 ID: 19semse1
 PROG: spin
 LANG: C++
 */
/*
 * spin.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
//#ifndef ONLINE_JUDGE
	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);
//#endif

	int d[5], sp[5], w, a, b;
	memset(d, 0, sizeof d);
	vector<pair<int, int> > wedges[5];
	for (int i = 0; i < 5; i++) {
		cin >> sp[i] >> w;
		while (w--) {
			cin >> a >> b;
			wedges[i].push_back(make_pair(a, b));
		}
	}
	for (int i = 0; i < 360; i++) {
		int light[360];
		fill(light, light + 360, 1);
		for (int j = 0; j < 5; j++) {
			int pass[360];
			fill(pass, pass + 360, 0);
			for (int k = 0; k < (int) wedges[j].size(); k++)
				for (int dd = 0; dd <= wedges[j][k].second; dd++)
					pass[(d[j] + wedges[j][k].first + dd) % 360] = 1;
			for (int k = 0; k < 360; k++)
				light[k] &= pass[k];
			d[j] = (d[j] + sp[j]) % 360;
		}
		for (int j = 0; j < 360; j++)
			if (light[j]) {
				cout << i << endl;
				return 0;
			}
	}
	cout << "none" << endl;
	return 0;
}
