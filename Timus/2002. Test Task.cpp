/*
 * 2002. Test Task.cpp
 *
 *  Created on: Aug 2, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<string, string> database;
set<string> in;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	string op, user, pass;
	scanf("%d", &n);
	while (n--) {
		cin >> op >> user;
		if (op != "logout")
			cin >> pass;
		if (op == "register") {
			if (database.count(user))
				cout << "fail: user already exists\n";
			else {
				cout << "success: new user added\n";
				database[user] = pass;
			}
		} else if (op == "login") {
			if (!database.count(user))
				cout << "fail: no such user\n";
			else if (database[user] != pass)
				cout << "fail: incorrect password\n";
			else if (in.count(user))
				cout << "fail: already logged in\n";
			else {
				cout << "success: user logged in\n";
				in.insert(user);
			}
		} else {
			if (!database.count(user))
				cout << "fail: no such user\n";
			else if (!in.count(user))
				cout << "fail: already logged out\n";
			else {
				cout << "success: user logged out\n";
				in.erase(user);
			}
		}
	}
	return 0;
}
