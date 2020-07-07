/*
 * 551B. ZgukistringZ.cpp
 *
 *  Created on: Jun 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnta[26], cntb[26], cntc[26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < (int) a.size(); i++)
		cnta[a[i] - 'a']++;
	for (int i = 0; i < (int) b.size(); i++)
		cntb[b[i] - 'a']++;
	for (int i = 0; i < (int) c.size(); i++)
		cntc[c[i] - 'a']++;
	int maxB = 1 << 28, maxi = 0, maxC = 0;
	for (int i = 0; i < 26; i++)
		if (cntb[i])
			maxB = min(maxB, cnta[i] / cntb[i]);
	for (int i = 0; i <= maxB; i++) {
		int temp = 1 << 28;
		for (int j = 0; j < 26; j++)
			if (cntc[j])
				temp = min(temp, (cnta[j] - i * cntb[j]) / cntc[j]);
		if (i + temp > maxi)
			maxi = i + temp, maxC = temp;
	}
	for (int i = 0; i < maxi - maxC; i++)
		cout << b;
	for (int i = 0; i < maxC; i++)
		cout << c;
	for (int i = 0; i < 26; i++) {
		cnta[i] -= (maxi - maxC) * cntb[i] + maxC * cntc[i];
		while (cnta[i]) {
			cout << (char) ('a' + i);
			cnta[i]--;
		}
	}
	cout << endl;
	return 0;
}
