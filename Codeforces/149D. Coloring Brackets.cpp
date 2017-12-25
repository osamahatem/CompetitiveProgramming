/*
 * 149D. Coloring Brackets.cpp
 *
 *  Created on: Dec 25, 2017
 *      Author: Osama Hatem
 */
 
/*
A correct bracket sequence can be viewed as an opening bracket followed by a
number of disjoint, correct, bracket sequences, possibly zero, then a closing
bracket. Let's call those siblings, and the enclosing brackets the parent
sequence. The state of the DP is as follows:
	idx:	the index of the opening bracket of the current sequence.
	before:	the colour of the closing bracket of the preceding sibling, or the
			colour of the opening bracket of the parent sequence in case the
			current sequence is the first child.
	after:	the colour of the closing bracket of the parent sequence.
The DP tries all combinations not violating the preceding sibling and/or the
parent sequence, if relevant, and then calls itself on the next sibling and the
first child.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;

string in;
int match[705];
long long dp[705][3][3];

long long solve(int idx, int before, int after) {
	if (idx == (int) in.size() || in[idx] == ')')
		return 1;
	long long &ret = dp[idx][before][after];
	if (~ret)
		return ret;
	ret = 0;
	bool vbe = idx > 0;
	bool vaf = match[idx] + 1 < (int) in.size() && in[match[idx] + 1] == ')';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((i && j) || (!i && !j))
				continue;
			if (i && vbe && i == before)
				continue;
			if (j && vaf && j == after)
				continue;
			ret = (ret + solve(idx + 1, i, j) * solve(match[idx] + 1, j, after))
					% MOD;
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> in;
	vector<int> br;
	for (int i = 0; i < (int) in.size(); i++) {
		if (in[i] == '(')
			br.push_back(i);
		else {
			match[br.back()] = i;
			br.pop_back();
		}
	}
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0, 0) << endl;
	return 0;
}
