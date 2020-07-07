/*
 * 260B. Ancient Prophesy.cpp
 *
 *  Created on: May 8, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[100005];
map<string, int> cnt;
int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool valid(string date) {
	int d = 0;
	for (int i = 0; i < 10; i++)
		d += date[i] <= '9' && date[i] >= '0';
	if (d != 8 || date[2] != '-' || date[5] != '-')
		return false;
	d = 0;
	int m = 0, y = 0;
	for (int i = 0; i < 2; i++)
		d = d * 10 + date[i] - '0';
	for (int i = 3; i < 5; i++)
		m = m * 10 + date[i] - '0';
	for (int i = 6; i < 10; i++)
		y = y * 10 + date[i] - '0';
	return y > 2012 && y < 2016 && m > 0 && m < 13 && d > 0 && d <= days[m - 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s", in);
	string all = in;
	for (int i = 0; i + 9 < (int) all.size(); i++)
		if (valid(all.substr(i, 10)))
			cnt[all.substr(i, 10)]++;
	string ans = "";
	int maxi = 0;
	for (auto it = cnt.begin(); it != cnt.end(); it++)
		if (it->second > maxi)
			maxi = it->second, ans = it->first;
	printf("%s\n", ans.c_str());
	return 0;
}
