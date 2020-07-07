/*
 * 589A. Email Aliases.cpp
 *
 *  Created on: Oct 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char buff[105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	map<string, vector<string>> ans;
	while (n--) {
		scanf("%s", buff);
		string temp = buff;
		int at = find(temp.begin(), temp.end(), '@') - temp.begin();
		string login = temp.substr(0, at), loginn = "";
		string domain = temp.substr(at + 1, temp.size() - (at + 1));
		for (int i = 0; i < (int) domain.size(); i++)
			domain[i] = tolower(domain[i]);
		bool flag = 0;
		if (domain == "bmail.com") {
			int plus = find(login.begin(), login.end(), '+') - login.begin();
			login = login.substr(0, plus);
			flag = 1;
		}
		for (int i = 0; i < (int) login.size(); i++)
			if (login[i] != '.' || !flag)
				loginn += tolower(login[i]);
		string cannon = loginn + "@" + domain;
		ans[cannon].push_back(temp);
	}
	printf("%d\n", ans.size());
	for (auto it = ans.begin(); it != ans.end(); it++) {
		printf("%d", (it->second).size());
		for (int i = 0; i < (int) (it->second).size(); i++)
			printf(" %s", (it->second)[i].c_str());
		printf("\n");
	}
	return 0;
}
