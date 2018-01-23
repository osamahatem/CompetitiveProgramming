/*
 * 3736 - Consanguine Calculations.cpp
 *
 *  Created on: Jan 23, 2018
 *      Author: Osama Hatem
 */
 
/*
Simple brute force: try everything and print valid answers.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const string ALL = "ABO+-";

string A, B, C;
vector<string> types;

string getType(string x) {
	if (x[1] < x[0])
		swap(x[1], x[0]);
	if (x[3] == '+')
		swap(x[2], x[3]);
	string ret = string() + x[0];
	if (x[1] != 'O' && x[1] != x[0])
		ret += x[1];
	ret += x[2];
	return ret;
}

vector<string> inherit(string a, string b) {
	vector<string> ret;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 2; k < 4; k++)
				for (int l = 2; l < 4; l++)
					ret.push_back(
							getType(string() + a[i] + b[j] + a[k] + b[l]));
	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	return ret;
}

void print(vector<string> ans) {
	if (ans.empty()) {
		cout << "IMPOSSIBLE";
		return;
	}
	if (ans.size() != 1)
		cout << "{";
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			cout << ", ";
		cout << ans[i];
	}
	if (ans.size() != 1)
		cout << "}";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
			for (int k = 3; k < 5; k++)
				for (int l = k; l < 5; l++)
					types.push_back(
							string() + ALL[i] + ALL[j] + ALL[k] + ALL[l]);

	int T = 0;
	while (cin >> A >> B >> C, A != "E") {
		vector<string> ans;
		for (int i = 0; i < (int) types.size(); i++) {
			for (int j = 0; j < (int) types.size(); j++) {
				if (getType(types[i]) != A && A != "?")
					continue;
				if (getType(types[j]) != B && B != "?")
					continue;
				vector<string> temp = inherit(types[i], types[j]);
				if (C == "?")
					ans.insert(ans.end(), temp.begin(), temp.end());
				else if (find(temp.begin(), temp.end(), C) != temp.end())
					ans.push_back(getType(A == "?" ? types[i] : types[j]));
			}
		}
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		cout << "Case " << ++T << ": ";
		if (A != "?")
			cout << A;
		else
			print(ans);
		cout << " ";
		if (B != "?")
			cout << B;
		else
			print(ans);
		cout << " ";
		if (C != "?")
			cout << C;
		else
			print(ans);
		cout << endl;
	}
	return 0;
}
