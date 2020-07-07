/*
 * 724A. Checking the Calendar.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string dayNames[] = { "monday", "tuesday", "wednesday", "thursday", "friday",
		"saturday", "sunday" };

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string a, b;
	cin >> a >> b;
	int idxA = find(dayNames, dayNames + 7, a) - dayNames;
	int idxB = find(dayNames, dayNames + 7, b) - dayNames;
	bool ans = false;
	for (int i = 1; i < 12; i++)
		ans |= ((idxA + daysPerMonth[i - 1]) % 7) == idxB;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
