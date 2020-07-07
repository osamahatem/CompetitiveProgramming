/*
 * 12667 - Last Blood.cpp
 *
 *  Created on: Aug 31, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool AC[15][105];
pair<int, int> last[15];
int n, m, t;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int tm, id;
	char p;
	string v;
	cin >> n >> t >> m;
	for (int i = 0; i < n; i++)
		last[i] = make_pair(-1, -1);
	while (m--) {
		cin >> tm >> id >> p >> v;
		if (v == "Yes" && !AC[p - 'A'][id]) {
			AC[p - 'A'][id] = 1;
			last[p - 'A'] = make_pair(tm, id);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << (char) (i + 'A') << " ";
		if (last[i].first == -1)
			cout << "- -\n";
		else
			cout << last[i].first << " " << last[i].second << "\n";
	}
	return 0;
}
