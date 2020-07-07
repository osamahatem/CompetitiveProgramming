/*
 ID: 19semse1
 PROG: preface
 LANG: C++
 */
/*
 * preface.cpp
 *
 *  Created on: Mar 8, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<pair<int, string> > roman;
map<char, int> cnt;

int main() {
//#ifndef ONLINE_JUDGE
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
//#endif

	roman.push_back(make_pair(1, "I"));
	roman.push_back(make_pair(4, "IV"));
	roman.push_back(make_pair(5, "V"));
	roman.push_back(make_pair(9, "IX"));
	roman.push_back(make_pair(10, "X"));
	roman.push_back(make_pair(40, "XL"));
	roman.push_back(make_pair(50, "L"));
	roman.push_back(make_pair(90, "XC"));
	roman.push_back(make_pair(100, "C"));
	roman.push_back(make_pair(400, "CD"));
	roman.push_back(make_pair(500, "D"));
	roman.push_back(make_pair(900, "CM"));
	roman.push_back(make_pair(1000, "M"));
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp = i;
		for (int j = 12; j >= 0; j--)
			while (temp >= roman[j].first) {
				temp -= roman[j].first;
				for (int l = 0; l < (int) roman[j].second.size(); l++)
					cnt[roman[j].second[l]]++;
			}
	}
	if (cnt['I'])
		cout << "I " << cnt['I'] << endl;
	if (cnt['V'])
		cout << "V " << cnt['V'] << endl;
	if (cnt['X'])
		cout << "X " << cnt['X'] << endl;
	if (cnt['L'])
		cout << "L " << cnt['L'] << endl;
	if (cnt['C'])
		cout << "C " << cnt['C'] << endl;
	if (cnt['D'])
		cout << "D " << cnt['D'] << endl;
	if (cnt['M'])
		cout << "M " << cnt['M'] << endl;
	return 0;
}
