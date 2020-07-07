/*
 * B. Bad Printer (B).cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const string LOW = "20110000";
const string HI = "20159999";

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, maxi = 0, gr[15];
	string a, all[15];
	cin >> n >> a;
	for (int i = 0; i < n; i++)
		cin >> all[i] >> gr[i];
	for (int i = 0; i < n; i++) {
		if (all[i] == a) {
			maxi = gr[i];
			break;
		}
		bool valid = 1;
		for (int j = 0; j < 8; j++)
			if (a[j] != all[i][j] && all[i][j] != '?')
				valid = 0;
		if (!valid)
			continue;
		valid = 1;
		set<string> other;
		other.insert(a);
		for (int j = 0; j < n; j++)
			if (count(all[j].begin(), all[j].end(), '?'))
				other.insert(all[j]);
		for (int j = 0; j < n; j++) {
			if (i == j || count(all[j].begin(), all[j].end(), '?'))
				continue;
			string temp = all[j];
			bool in = 0;
			for (int k = 0; k < 8; k++)
				if (temp[k] == '?')
					for (int kk = '0'; !in && kk <= '9'; kk++) {
						temp[k] = kk;
						if (temp >= LOW && temp <= HI && !other.count(temp)) {
							other.insert(temp);
							in = 1;
						}
					}
			if (!in)
				valid = 0;
		}
		if (valid)
			maxi = max(maxi, gr[i]);
	}
	cout << maxi << endl;
	return 0;
}
