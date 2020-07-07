/*
 ID: 19semse1
 PROG: holstein
 LANG: C++
 */
/*
 * holstein.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
//#ifndef ONLINE_JUDGE
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);
//#endif

	int v, g, need[25], val[15][25];
	cin >> v;
	for (int i = 0; i < v; i++)
		cin >> need[i];
	cin >> g;
	for (int i = 0; i < g; i++)
		for (int j = 0; j < v; j++)
			cin >> val[i][j];
	int mini = 20, mask;
	for (int i = 0; i < (1 << g); i++) {
		int temp[25], cnt = 0;
		memset(temp, 0, sizeof temp);
		for (int j = 0; j < g; j++)
			if (i & (1 << j)) {
				cnt++;
				for (int k = 0; k < v; k++)
					temp[k] += val[j][k];
			}
		bool flag = 1;
		for (int j = 0; j < v; j++)
			if (temp[j] < need[j])
				flag = 0;
		if (flag && cnt < mini)
			mini = cnt, mask = i;
	}
	cout << mini;
	for (int i = 0; i < g; i++)
		if (mask & (1 << i))
			cout << " " << i + 1;
	cout << endl;
	return 0;
}
