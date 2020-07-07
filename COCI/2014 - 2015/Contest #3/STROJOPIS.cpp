/*
 * STROJOPIS.cpp
 *
 *  Created on: Nov 29, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<char, int> all;
int ans[8];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	all['1'] = all['Q'] = all['A'] = all['Z'] = 0;
	all['2'] = all['W'] = all['S'] = all['X'] = 1;
	all['3'] = all['E'] = all['D'] = all['C'] = 2;
	all['4'] = all['R'] = all['F'] = all['V'] = 3;
	all['5'] = all['T'] = all['G'] = all['B'] = 3;
	all['6'] = all['Y'] = all['H'] = all['N'] = 4;
	all['7'] = all['U'] = all['J'] = all['M'] = 4;
	all['8'] = all['I'] = all['K'] = all[','] = 5;
	all['9'] = all['O'] = all['L'] = all['.'] = 6;
	all['0'] = all['P'] = all[';'] = all['/'] = 7;
	all['-'] = all['['] = all['\''] = all['='] = all[']'] = 7;

	string in;
	cin >> in;
	for (int i = 0; i < (int) in.size(); i++)
		ans[all[in[i]]]++;
	for (int i = 0; i < 8; i++)
		cout << ans[i] << endl;
	return 0;
}
