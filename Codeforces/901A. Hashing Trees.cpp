/*
 * 901A. Hashing Trees.cpp
 *
 *  Created on: Dec 19, 2017
 *      Author: Osama Hatem
 */
 
/*
If 2 consecutive levels have more than 1 node in them, there can be more than
one valid tree. We can generate 2 different trees by simply distributing nodes
differently in those 2 aforementioned levels.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int h, arr[MAXN], id;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> h;
	for (int i = 0; i <= h; i++)
		cin >> arr[i];
	bool flag = false;
	for (int i = 0; i < h; i++)
		flag |= (arr[i] > 1 && arr[i + 1] > 1);
	if (!flag) {
		cout << "perfect" << endl;
		return 0;
	}
	cout << "ambiguous" << endl;
	cout << "0";
	id = 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 0; j < arr[i]; j++)
			cout << " " << id;
		id += arr[i];
	}
	id = 1;
	cout << endl << "0";
	for (int i = 1; i <= h; i++) {
		for (int j = 0; j < arr[i]; j++)
			cout << " " << (j ? id : id - arr[i - 1] + 1);
		id += arr[i];
	}
	cout << endl;
	return 0;
}
