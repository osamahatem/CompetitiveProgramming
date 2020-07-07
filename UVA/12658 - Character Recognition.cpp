/*
 * 12658 - Character Recognition.cpp
 *
 *  Created on: Aug 31, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string in[6];
char one[5][4] = { ".*.", ".*.", ".*.", ".*.", ".*." };
char two[5][4] = { "***", "..*", "***", "*..", "***" };
char thr[5][4] = { "***", "..*", "***", "..*", "***" };

bool cmp(int c, char arr[5][4]) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
			if (arr[j][i] != in[j][i + c])
				return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < 5; i++)
		cin >> in[i];
	for (int i = 0; i < 4 * n; i += 4) {
		if (cmp(i, one))
			cout << "1";
		else if (cmp(i, two))
			cout << "2";
		else
			cout << "3";
	}
	cout << "\n";
	return 0;
}
