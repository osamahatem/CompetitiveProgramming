/*
 * SRM432-D1-500 - GroupedWord.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: Osama Hatem
 */

/*
 * First, we join all strings that consist of the same single letter, and then
 * we concatenate them to other string beginning or ending with that letter.
 * For the resulting strings, we join all pairs s and t, such that s ends with
 * the first letter of t.
 * If afterwards, a letter appears in more than one string, the answer is
 * "IMPOSSIBLE". If not, the answer is "MANY" in case the remaining is more than
 * one string, otherwise it is the remaining string.
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

class GroupedWord {
	int cnt[26];

	bool is_one_char(string s) {
		for (int i = 1; s[i]; i++)
			if (s[i] != s[i - 1])
				return false;
		return true;
	}

	bool check(string s) {
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; s[i]; i++) {
			if (i && cnt[s[i] - 'a'] && s[i - 1] != s[i])
				return false;
			cnt[s[i] - 'a']++;
		}
		return true;
	}

	bool check(string a, string b) {
		for (int i = 0; a[i]; i++)
			for (int j = 0; b[j]; j++)
				if (a[i] == b[j])
					return false;
		return true;
	}

public:
	string restore(vector<string> parts) {
		vector<string> prep;

		for (int i = 0; i < (int) parts.size(); i++) {
			bool flag = true;
			for (int j = 0; flag && j < (int) prep.size(); j++) {
				if (prep[j][0] == parts[i][0] && is_one_char(parts[i])
						&& is_one_char(prep[j]))
					prep[j] += parts[i], flag = false;
			}
			if (flag)
				prep.push_back(parts[i]);
		}

		parts = prep;
		prep.clear();

		for (int i = 0; i < (int) parts.size(); i++) {
			bool flag = true;
			for (int j = 0; flag && j < (int) prep.size(); j++) {
				if (prep[j].back() == parts[i][0] && is_one_char(parts[i]))
					prep[j] += parts[i], flag = false;
				else if (prep[j][0] == parts[i][0] && is_one_char(parts[i]))
					prep[j] = parts[i] + prep[j], flag = false;
			}
			if (flag)
				prep.push_back(parts[i]);
		}

		parts = prep;
		prep.clear();

		for (int i = 0; i < (int) parts.size(); i++) {
			bool flag = true;
			for (int j = 0; flag && j < (int) prep.size(); j++) {
				if (prep[j].back() == parts[i][0])
					prep[j] += parts[i], flag = false;
				else if (prep[j][0] == parts[i].back())
					prep[j] = parts[i] + prep[j], flag = false;

				if (!flag) {
					parts.push_back(prep[j]);
					prep.erase(prep.begin() + j);
					j--;
				}
			}
			if (flag)
				prep.push_back(parts[i]);
		}

		for (int i = 0; i < (int) prep.size(); i++) {
			if (!check(prep[i]))
				return "IMPOSSIBLE";
			for (int j = i + 1; j < (int) prep.size(); j++)
				if (!check(prep[i], prep[j]))
					return "IMPOSSIBLE";
		}
		return prep.size() == 1 ? prep[0] : "MANY";
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	GroupedWord solve;
	cout << solve.restore( { "aaa", "a", "aa" }) << endl;
	cout << solve.restore( { "ab", "bba" }) << endl;
	cout << solve.restore( { "te", "st" }) << endl;
	cout << solve.restore( { "te", "s", "t" }) << endl;
	cout << solve.restore( { "orr", "rd", "woo", "www" }) << endl;
	cout << solve.restore( { "abcb" }) << endl;
	return 0;
}
