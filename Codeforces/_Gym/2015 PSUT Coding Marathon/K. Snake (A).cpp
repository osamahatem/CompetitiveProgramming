/*
 * K. Snake (A).cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char grid[40];
int sr, sc, er, ec;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int i = 0; i < 16; i++) {
		cin >> grid;
		for (int j = 0; j < 32; j++)
			if (grid[j] == ':')
				sr = i, sc = j;
			else if (grid[j] == 'E')
				er = i, ec = j;
	}
	string in;
	cin >> in;
	for (int i = 0; i < (int) in.size(); i++) {
		sr += (in[i] == 'v' ? 1 : (in[i] == '^' ? -1 : 0));
		sc += (in[i] == '>' ? 1 : (in[i] == '<' ? -1 : 0));
	}
	cout << (sr == er && sc == ec ? "Yes" : "No") << endl;
	return 0;
}
