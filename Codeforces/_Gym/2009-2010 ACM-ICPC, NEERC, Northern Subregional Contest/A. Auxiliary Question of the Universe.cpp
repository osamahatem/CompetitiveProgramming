/*
 * A. Auxiliary Question of the Universe.cpp
 *
 *  Created on: Oct 7, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[1005];

string checkExp(string exp) {
	char last = '+';
	string ret = "";
	for (int i = 0; exp[i]; i++) {
		if (exp[i] == '+') {
			if (last == '+')
				ret += '1';
			ret += exp[i];
		} else
			ret += exp[i];
		last = exp[i];
	}
	if (last == '+')
		ret += '1';
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("auxiliary.in", "r", stdin);
	freopen("auxiliary.out", "w", stdout);

	scanf("%s", in);
	string ans = "", temp = "";
	vector<string> exps;
	for (int i = 0; in[i]; i++) {
		if (in[i] == '(' || in[i] == ')') {
			if (temp.size()) {
				exps.push_back(temp);
				temp.clear();
			}
			exps.push_back(string() + in[i]);
		} else
			temp += in[i];
	}
	if (temp.size())
		exps.push_back(temp);
	int cnt = 0;
	for (int i = 0; i < (int) exps.size(); i++) {
		if (exps[i][0] != '(' && exps[i][0] != ')')
			ans += checkExp(exps[i]);
		else if (exps[i][0] == '(') {
			if (i && exps[i - 1] != "(")
				ans += "+";
			ans += exps[i];
			cnt++;
		} else {
			cnt--;
			if (cnt < 0) {
				if (i)
					ans += "+";
				while (cnt < 0)
					ans += "(", cnt++;
				ans += "1" + exps[i];
			} else {
				if (exps[i - 1] == "(")
					ans += "1";
				ans += exps[i];
			}
		}
	}
	if (cnt > 0 && exps.back() == "(")
		ans += "1";
	while (cnt > 0)
		ans += ")", cnt--;
	printf("%s\n", ans.c_str());
	return 0;
}
