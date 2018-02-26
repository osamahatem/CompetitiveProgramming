/*
 * 936C. Lock Puzzle.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Osama Hatem
 */
 
/*
First, let's check if the count of every character is the same in both strings.
If this is not the case, we cannot reach the target.
Let's first attempt to build the target one character at a time. Let's assume
that the built-so-far part of the target is present at the start of the current
string, reversed. We need to add the next character to the start of it. The only
way to achieve that is to perform a shift such that the first character of the
shifted part is the desired one. This successfully adds the character, but
possibly shifts the built-so-far part a few positions from the start. We can get
it back to the desired position, but it takes 3 extra moves, for a total of 4
moves per character, which exceeds the required 6100 move limit.
We can observe however, that with 2 extra moves instead of 3, we can get the
built-so-far part to the start string, but in the reverse order. We can use that
by starting to build the target string from the middle, so we switch each move
by adding once to the end and once to the beginning. This way, we can use only 3
moves per character instead of 4, which fits the limits.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, cnt[26];
string s, t;

string shift(string str, int x) {
	string temp = str.substr(n - x);
	reverse(temp.begin(), temp.end());
	return temp + str.substr(0, n - x);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> s >> t;

	for (int i = 0; s[i]; i++)
		cnt[s[i] - 'a']++;
	for (int i = 0; t[i]; i++)
		cnt[t[i] - 'a']--;
	for (int i = 0; i < 26; i++)
		if (cnt[i] != 0) {
			cout << "-1" << endl;
			return 0;
		}

	int b = n / 2 - 1, e = n / 2, idx;
	vector<int> ans;
	char c;
	for (int i = 0; i < n; i++) {
		if (i & 1)
			c = t[b--];
		else
			c = t[e++];
		for (idx = n - 1; s[idx] != c; idx--)
			;

		ans.push_back(n - idx), s = shift(s, n - idx);
		ans.push_back(idx - i), s = shift(s, idx - i);
		ans.push_back(n), s = shift(s, n);
	}
	if (n % 2 == 0) {
		ans.push_back(n);
		s = shift(s, n);
	}

	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
