/*
 * 2996 - Insecure in Prague.cpp
 *
 *  Created on: Dec 23, 2017
 *      Author: Osama Hatem
 */
 
/*
Pre-calculate for all combinations of string lengths, starting positions and
skipping steps, the indices visited in order, then perform a brute force.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int sz, vis[44], id = 0;
vector<int> pre[44][44][44];

bool check(string &word, string &rem, int i) {
	for (int s = 0; rem[s]; s++) {
		if (word[0] != rem[s])
			continue;
		for (int j = i + 1; j < sz; j++) {
			int idx = pre[rem.size()][s][j][0], cur = 0;
			while (cur < (int) word.size()) {
				if (rem[idx] != word[cur])
					break;
				cur++;
				if (cur < (int) rem.size())
					idx = pre[rem.size()][s][j][cur];
			}
			if (cur == (int) word.size())
				return true;
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int n = 1; n <= 40; n++) {
		for (int s = 0; s < 40; s++) {
			for (int i = 0; i < 40; i++) {
				id++;
				int idx = s, cnt = n;
				while (1) {
					pre[n][s][i].push_back(idx);
					cnt--;
					if (!cnt)
						break;
					vis[idx] = id;
					int temp = i % cnt;
					for (; temp || vis[idx] == id; idx = (idx + 1) % n) {
						if (vis[idx] != id)
							temp--;
					}
				}
			}
		}
	}

	int t = 0;
	string code;
	while (cin >> code, code != "X") {
		sz = code.size();
		set<string> ans;
		for (int n = sz / 2; (int) ans.size() == 0 && n; n--) {
			for (int s = 0; (int) ans.size() < 2 && s < sz; s++) {
				for (int i = 0; (int) ans.size() < 2 && i < sz; i++) {
					string ret = "", rem = "";
					int idx = pre[sz][s][i][0];
					id++;
					while ((int) ret.size() < n) {
						ret += code[idx];
						vis[idx] = id;
						idx = pre[sz][s][i][ret.size()];
					}
					for (int j = 0; j < sz; j++)
						if (vis[j] != id)
							rem += code[j];
					if (check(ret, rem, i))
						ans.insert(ret);
				}
			}
		}
		cout << "Code " << ++t << ": ";
		if ((int) ans.size() == 1)
			cout << *ans.begin() << endl;
		else
			cout << "Codeword not unique" << endl;
	}
	return 0;
}
