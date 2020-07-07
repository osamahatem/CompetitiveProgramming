/*
 * 1.LandAcquisition.cpp
 *
 *  Created on: Jan 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<pair<int, int> > land;
long long dp[50005];
vector<int> bestLine, bestLineID;

int inter(int m1, long long c1) {
	int ID = bestLineID.back();
	int m2 = land[ID].second;
	long long c2 = dp[ID + 1];
	double temp = c2 - c1;
	temp /= m1 - m2;
	return (int) ceil(temp);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x, y;
	vector<pair<int, int> > in;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		in.push_back(make_pair(x, y));
	}
	sort(in.begin(), in.end(), greater<pair<int, int> >());
	for (int i = 0; i < (int) in.size(); i++) {
		land.push_back(in[i]);
		pair<int, int> temp = in[i];
		while (i < (int) in.size() && in[i].first <= temp.first
				&& in[i].second <= temp.second)
			i++;
		i--;
	}
	int sz = (int) land.size();
	dp[sz] = 0;
	bestLine.push_back(-(1 << 28)), bestLineID.push_back(sz - 1);
	for (int i = sz - 1; i >= 0; i--) {
		int best = upper_bound(bestLine.begin(), bestLine.end(), land[i].first)
				- bestLine.begin() - 1;
		int ID = bestLineID[best];
		dp[i] = (long long) land[i].first * land[ID].second + dp[ID + 1];
		if (!i)
			break;
		int m1 = land[i - 1].second;
		long long c1 = dp[i];
		while (inter(m1, c1) <= bestLine.back())
			bestLine.pop_back(), bestLineID.pop_back();
		bestLine.push_back(inter(m1, c1)), bestLineID.push_back(i - 1);
	}
	cout << dp[0] << endl;
	return 0;
}
