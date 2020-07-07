/*
 * G. No Negations.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char neg(char x) {
	if (x == '+')
		return '*';
	if (x == '*')
		return '+';
	if (x == '[')
		return '(';
	if (x == ']')
		return ')';
	if (x == '(')
		return '[';
	if (x == ')')
		return ']';
	if (islower(x))
		return toupper(x);
	return tolower(x);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string in;
	cin >> in;
	bool flag;
	do {
		flag = 0;
		for (int i = 0; i < (int) in.size(); i++)
			if (in[i] == '[') {
				int c = 1, e = -1;
				for (int j = i + 1; j < (int) in.size(); j++) {
					if (in[j] == '[')
						c++;
					if (in[j] == ']')
						c--;
					if (in[j] == ']' && !c) {
						e = j;
						break;
					}
				}
				flag = 1;
				for (int j = i; j <= e; j++) {
					if (j > i && in[j] == '[') {
						in[j] = neg(in[j]);
						int c = 1;
						do {
							if (in[j] == '[')
								c++;
							if (in[j] == ']')
								c--;
							j++;
						} while (c);
						j--;
					}
					if (j > i && in[j] == '(') {
						in[j] = neg(in[j]);
						int c = 1;
						do {
							if (in[j] == '(')
								c++;
							if (in[j] == ')')
								c--;
							j++;
						} while (c);
						j--;
					}
					in[j] = neg(in[j]);
				}
				break;
			}
	} while (flag);
	cout << in << endl;
	return 0;
}
