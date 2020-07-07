/*
 * 1990. Podracing.cpp
 *
 *  Created on: Aug 4, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<pair<int, int> > L, R;
pair<double, double> b;

pair<double, double> getBorders(int l, int r, int ym) {
	pair<double, double> ans;
	if (ym == L[l].first)
		ans.first = L[l].second;
	else {
		double x1 = L[l - 1].second, x2 = L[l].second;
		double y1 = L[l - 1].first, y2 = L[l].first;
		ans.first = (x1 * y2 - x1 * ym + x2 * ym - x2 * y1) / (y2 - y1);
	}
	if (ym == R[r].first)
		ans.second = R[r].second;
	else {
		double x1 = R[r - 1].second, x2 = R[r].second;
		double y1 = R[r - 1].first, y2 = R[r].first;
		ans.second = (x1 * y2 - x1 * ym + x2 * ym - x2 * y1) / (y2 - y1);
	}
	return ans;
}

double solve(int l, int r, int y, vector<int> &curCam) {
	if (y < L[0].first || y > L.back().first)
		return 1e10;
	sort(curCam.begin(), curCam.end());
	vector<double> temp;
	b = getBorders(l, r, y);
	temp.push_back(b.first);
	for (int i = 0; i < (int) curCam.size(); i++) {
		if (curCam[i] < b.first || curCam[i] > b.second)
			continue;
		temp.push_back(curCam[i]);
	}
	temp.push_back(b.second);
	double ret = 0.0;
	for (int i = 1; i < (int) temp.size(); i++)
		ret = max(ret, temp[i] - temp[i - 1]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x, y, l, r;
	double ans = 1e10;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		L.push_back(make_pair(y, x));
	}
	scanf("%d", &n);
	l = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		R.push_back(make_pair(y, x));
		while (L[l].first < y)
			l++;
		b = getBorders(l, i, y);
		ans = min(ans, b.second - b.first);
	}
	r = 0;
	for (int i = 0; i < (int) L.size(); i++) {
		y = L[i].first;
		while (R[r].first < y)
			r++;
		b = getBorders(i, r, y);
		ans = min(ans, b.second - b.first);
	}
	l = r = 0;
	vector<pair<int, vector<int> > > curCam;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		if (curCam.size() > 0 && curCam.back().first == y)
			curCam.back().second.push_back(x);
		else
			curCam.push_back(make_pair(y, vector<int>(1, x)));
	}
	for (int i = 0; i < (int) curCam.size(); i++) {
		while (l < (int) L.size() && L[l].first < curCam[i].first)
			l++;
		while (r < (int) R.size() && R[r].first < curCam[i].first)
			r++;
		ans = min(ans, solve(l, r, curCam[i].first, curCam[i].second));
	}
	printf("%.10f\n", ans);
	return 0;
}
