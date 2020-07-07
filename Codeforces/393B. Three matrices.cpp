/*
 * 393B. Three matrices.cpp
 *
 *  Created on: Aug 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int mat[175][175];
double A[175][175], B[175][175];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			A[i][j] = 0.5 * (mat[i][j] + mat[j][i]);
			B[i][j] = mat[i][j] - A[i][j];
		}
	cout << fixed << setprecision(4);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j)
				cout << " ";
			cout << A[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j)
				cout << " ";
			cout << B[i][j];
		}
		cout << endl;
	}
	return 0;
}
