/*
 * 1993. This cheeseburger you don't need.cpp
 *
 *  Created on: Aug 4, 2014
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

	string in, sub = "", obj = "", verb = "";
	bool flag = 1;
	getline(cin, in);
	int i = -1;
	while (i < (int) in.size()) {
		i++;
		if (in[i] == '(') {
			i++;
			while (in[i] != ')')
				sub += in[i++];
			continue;
		}
		if (in[i] == '{') {
			i++;
			while (in[i] != '}')
				obj += in[i++];
			continue;
		}
		if (in[i] == '[') {
			i++;
			while (in[i] != ']')
				verb += in[i++];
			continue;
		}
		if (in[i] == ',') {
			printf("%c", toupper(obj[0]));
			flag = 0;
			for (int j = 1; j < (int) obj.size(); j++)
				printf("%c", tolower(obj[j]));
			printf(" ");
			for (int j = 0; j < (int) sub.size(); j++)
				printf("%c", tolower(sub[j]));
			printf(" ");
			for (int j = 0; j < (int) verb.size(); j++)
				printf("%c", tolower(verb[j]));
			printf(",");
			obj.clear();
			sub.clear();
			verb.clear();
			i++;
			while (in[i] != '{' && in[i] != '(' && in[i] != '[')
				printf("%c", tolower(in[i++]));
			i--;
			continue;
		}
	}
	if (flag)
		obj[0] = toupper(obj[0]);
	printf("%c", obj[0]);
	for (int j = 1; j < (int) obj.size(); j++)
		printf("%c", tolower(obj[j]));
	printf(" ");
	for (int j = 0; j < (int) sub.size(); j++)
		printf("%c", tolower(sub[j]));
	printf(" ");
	for (int j = 0; j < (int) verb.size(); j++)
		printf("%c", tolower(verb[j]));
	printf("\n");
	return 0;
}
