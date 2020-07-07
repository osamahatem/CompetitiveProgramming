/*
 * TheBrickTowerMediumDivOne.cpp
 *
 *  Created on: Aug 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

class TheBrickTowerMediumDivOne {
public:
	vector<int> find(vector<int> h) {
		vector<int> ret;
		vector<pair<int, int>> temp;
		ret.push_back(0);
		for (int i = 1; i < (int) h.size(); i++) {
			if (h[i] <= h[ret.back()])
				ret.push_back(i);
			else
				temp.push_back(make_pair(h[i], i));
		}
		sort(temp.begin(), temp.end());
		for (int i = 0; i < (int) temp.size(); i++)
			ret.push_back(temp[i].second);
		return ret;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	return 0;
}
