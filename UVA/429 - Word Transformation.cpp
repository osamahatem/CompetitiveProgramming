/*
 * 429 - Word Transformation.cpp
 *
 *  Created on: Sep 12, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<string> dict;
char temp[25];
int vis[205], id;

bool valid(string a, string b) {
	if (a.size() != b.size())
		return false;
	int cnt = 0;
	for (int i = 0; i < (int) a.size(); i++)
		if (a[i] != b[i])
			cnt++;
	return cnt == 1;
}

int BFS(string a, string b) {
	id++;
	int idx = find(dict.begin(), dict.end(), a) - dict.begin(), steps = 0;
	queue<int> Q;
	Q.push(idx), vis[idx] = id;
	while (Q.size()) {
		int sz = Q.size();
		while (sz--) {
			int cur = Q.front();
			Q.pop();
			if (dict[cur] == b)
				return steps;
			for (int i = 0; i < (int) dict.size(); i++)
				if (vis[i] != id && valid(dict[cur], dict[i]))
					Q.push(i), vis[i] = id;
		}
		steps++;
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		dict.clear();
		while (scanf("%s", temp), temp[0] != '*')
			dict.push_back(temp);
		gets(temp);
		while (gets(temp) != NULL) {
			if (!temp[0])
				break;
			string a, b, tmp = temp;
			int f = tmp.find(' ');
			a = tmp.substr(0, f);
			b = tmp.substr(f + 1);
			printf("%s %s %d\n", a.c_str(), b.c_str(), BFS(a, b));
		}
		if (T)
			printf("\n");
	}
	return 0;
}
