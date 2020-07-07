/*
 * 10017 - The Never Ending Towers of Hanoi.cpp
 *
 *  Created on: Sep 28, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int moves;
deque<int> tow[3];

void display() {
	for (int j = 0; j < 3; j++) {
		cout << (char) ('A' + j) << "=>";
		for (int i = 0; i < (int) tow[j].size(); i++) {
			if (!i)
				cout << "  ";
			cout << " " << tow[j][i];
		}
		cout << "\n";
	}
	cout << "\n";
}

void solve(int n, int f, int sp, int to) {
	if (n == 0)
		return;
	solve(n - 1, f, to, sp);
	if (moves == 0)
		return;
	display();
	moves--;
	tow[to].push_back(tow[f].back());
	tow[f].pop_back();
	if (moves == 0)
		return;
	solve(n - 1, sp, f, to);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, cnt = 0;
	while (cin >> n >> moves, n) {
		cout << "Problem #" << ++cnt << "\n\n";
		tow[0].clear();
		tow[1].clear();
		tow[2].clear();
		for (int i = n; i > 0; i--)
			tow[0].push_back(i);
		moves++;
		solve(n, 0, 1, 2);
		if (moves)
			display();
	}
	return 0;
}
