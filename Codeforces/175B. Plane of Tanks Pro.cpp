/*
 * 175B. Plane of Tanks Pro.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, s, per[] = { 99, 90, 80, 50, 0 };
	string rnk[] = { "pro", "hardcore", "average", "random", "noob" };
	string name;
	map<string, int> score;
	map<string, int>::iterator it;
	cin >> n;
	while (n--) {
		cin >> name >> s;
		score[name] = max(score[name], s);
	}
	vector<string> names;
	vector<int> scores;
	for (it = score.begin(); it != score.end(); it++)
		names.push_back(it->first), scores.push_back(it->second);
	int sz = names.size();
	cout << sz << endl;
	for (int i = 0; i < sz; i++) {
		cout << names[i] << " ";
		int c = 0;
		for (int j = 0; j < sz; j++) {
			if (scores[i] >= scores[j])
				c++;
		}
		double p = 100.0 * c / sz;
		for (int j = 0; j < 5; j++)
			if (p >= per[j]) {
				cout << rnk[j] << endl;
				break;
			}
	}
	return 0;
}
