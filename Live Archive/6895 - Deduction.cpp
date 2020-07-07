/*
 * 6895 - Deduction.cpp
 *
 *  Created on: Oct 2, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N, t1, t2, t3, t3_to[1502];
bool ok[1502];
vector<int> T1;
vector<vector<int>> T2;
vector<set<int>> T3;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(ok, 0, sizeof ok);
		scanf("%d %d %d %d", &N, &t1, &t2, &t3);
		T1.clear();
		T2.clear();
		T3.clear();
		for (int i = 0; i < t1; i++) {
			int x;
			scanf("%d", &x);
			T1.push_back(x);
		}
		for (int i = 0; i < t2; i++) {
			int c, x;
			vector<int> temp;
			scanf("%d", &c);
			for (int j = 0; j < c; j++) {
				scanf("%d", &x);
				temp.push_back(x);
			}
			T2.push_back(temp);
		}
		for (int i = 0; i < t3; i++) {
			int c, x;
			set<int> temp;
			scanf("%d", &c);
			for (int j = 0; j < c; j++) {
				scanf("%d", &x);
				temp.insert(x);
			}
			T3.push_back(temp);
			scanf("%d", &t3_to[i]);
		}
		for (int i = 0; i < (int) T1.size(); i++) {
			ok[T1[i]] = true;
			for (int j = 0; j < (int) T3.size(); j++) {
				if (T3[j].count(T1[i])) {
					T3[j].erase(T1[i]);
					if (T3[j].empty())
						T1.push_back(t3_to[j]);
				}
			}
		}
		bool ret = true;
		for (int i = 0; i < t2; i++) {
			bool f = false;
			for (int j = 0; j < (int) T2[i].size(); j++)
				f |= !ok[T2[i][j]];
			ret &= f;
		}
		if (ret)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
