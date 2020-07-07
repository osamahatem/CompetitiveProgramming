/*
 * E. Proficiency Test (A).cpp
 *
 *  Created on: Sep 3, 2015
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

	string a, b;
	int cnt = 0;
	cin >> a >> b;
	for (int i = 0; i < 48; i++)
		if (islower(a[i]) && b[i] != toupper(a[i]))
			cnt++;
	cout << (cnt > 2 ? "Remove" : "Kafo") << endl;
	return 0;
}
