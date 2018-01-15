/*
 * 913E. Logical Expression.cpp
 *
 *  Created on: Jan 8, 2018
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/56992
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	string exp;
	int func, lvl;

	bool operator <(const node &n) const {
		if (exp.size() != n.exp.size())
			return exp.size() < n.exp.size();
		return exp < n.exp;
	}
};

string ans[256][3];
set<node> S;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	S.insert(node { "x", 15, 0 });
	S.insert(node { "y", 51, 0 });
	S.insert(node { "z", 85, 0 });
	while (S.size()) {
		node cur = *S.begin();
		S.erase(S.begin());
		if (ans[cur.func][cur.lvl].size())
			continue;
		ans[cur.func][cur.lvl] = cur.exp;

		if (cur.lvl == 0) {
			S.insert(node { "!" + cur.exp, (~cur.func) & 255, 0 });
			S.insert(node { cur.exp, cur.func, 1 });
			for (int i = 0; i < 256; i++) {
				if (ans[i][2].empty())
					continue;
				S.insert(node { "(" + ans[i][2] + ")", i, 0 });
			}
		}

		if (cur.lvl == 1) {
			S.insert(node { cur.exp, cur.func, 2 });
			for (int i = 0; i < 256; i++) {
				if (ans[i][0].empty())
					continue;
				string a = cur.exp, b = ans[i][0];
				if (b < a)
					swap(a, b);
				S.insert(node { a + "&" + b, cur.func & i, 1 });
			}
		}

		if (cur.lvl == 2) {
			S.insert(node { "(" + cur.exp + ")", cur.func, 0 });
			for (int i = 0; i < 256; i++) {
				if (ans[i][1].empty())
					continue;
				string a = cur.exp, b = ans[i][1];
				if (b < a)
					swap(a, b);
				S.insert(node { a + "|" + b, cur.func | i, 2 });
			}
		}
	}

	int n;
	cin >> n;
	string in;
	while (n--) {
		cin >> in;
		int x = 0;
		for (int i = 0; i < 8; i++)
			x = x * 2 + in[i] - '0';
		cout << ans[x][2] << endl;
	}
	return 0;
}
