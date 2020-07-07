/*
 * 550D. Regular Bridge.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int k;
	cin >> k;
	if (k == 1) {
		cout << "YES\n2 1\n1 2" << endl;
		return 0;
	}
	if (k % 2 == 0) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES\n" << 2 * k + 4 << " ";
	vector<pair<int, int> > edges;
	for (int i = 1; i < k + 1; i++) {
		if (i % 2 == 0 || i == k)
			edges.push_back(make_pair(i, i + 1));
		for (int j = i + 2; j <= k + 1; j++)
			edges.push_back(make_pair(i, j));
	}
	for (int i = 1; i < k; i++)
		edges.push_back(make_pair(k + 2, i));
	int sz = (int) edges.size();
	for (int i = 0; i < sz; i++)
		edges.push_back(
				make_pair(edges[i].first + k + 2, edges[i].second + k + 2));
	edges.push_back(make_pair(k + 2, 2 * k + 4));
	cout << edges.size() << endl;
	for (int i = 0; i < (int) edges.size(); i++)
		cout << edges[i].first << " " << edges[i].second << endl;
	return 0;
}
