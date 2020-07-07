/*
 * A. A Whole New Word.cpp
 *
 *  Created on: May 5, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N, L;
set<string> S;
vector<string> all;
bool let[10][26];

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		S.clear();
		memset(let, 0, sizeof let);

		cin >> N >> L;
		for (int i = 0; i < N; i++) {
			string x;
			cin >> x;
			S.insert(x);
			for (int j = 0; j < L; j++)
				let[j][x[j] - 'A'] = true;
		}

		string ans = "-";
		for (auto &s : S) {
			for (int i = 0; i < L; i++) {
				for (int j = 0; j < 26; j++) {
					if (!let[i][j])
						continue;
					string temp = s.substr(0, i);
					temp += 'A' + j;
					temp += s.substr(i + 1);
					if (!S.count(temp))
						ans = temp;
					if (ans != "-")
						break;
				}
				if (ans != "-")
					break;
			}
			if (ans != "-")
				break;
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
