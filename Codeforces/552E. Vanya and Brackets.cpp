/*
 * 552E. Vanya and Brackets.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<char, int> pre;

inline long long applyOP(long long a, long long b, char op) {
	return (op == '*' ? a * b : a + b);
}

long long evaluate(string exp) {
	stack<long long> val;
	stack<char> ops;
	for (int i = 0; i < (int) exp.size(); i++) {
		char t = exp[i];
		if (isdigit(t))
			val.push(t - '0');
		else if (t == '(')
			ops.push(t);
		else if (t == ')') {
			while (ops.top() != '(') {
				char op = ops.top();
				ops.pop();
				long long a = val.top();
				val.pop();
				long long b = val.top();
				val.pop();
				val.push(applyOP(a, b, op));
			}
			ops.pop();
		} else {
			while (!ops.empty() && pre[ops.top()] >= pre[t]) {
				char op = ops.top();
				ops.pop();
				long long a = val.top();
				val.pop();
				long long b = val.top();
				val.pop();
				val.push(applyOP(a, b, op));
			}
			ops.push(t);
		}
	}
	while (!ops.empty()) {
		char op = ops.top();
		ops.pop();
		long long a = val.top();
		val.pop();
		long long b = val.top();
		val.pop();
		val.push(applyOP(a, b, op));
	}
	return val.top();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	pre['('] = 0, pre['+'] = 1, pre['*'] = 2;
	string s;
	vector<int> pos;
	cin >> s;
	for (int i = 0; i < (int) s.size(); i++)
		if (s[i] == '*')
			pos.push_back(i);
	long long ans = evaluate(s);
	for (int i = 0; i < (int) pos.size(); i++) {
		string temp = "(" + s.substr(0, pos[i]) + ")"
				+ s.substr(pos[i], (int) s.size() - pos[i]);
		ans = max(ans, evaluate(temp));
		temp = s.substr(0, pos[i] + 1) + "("
				+ s.substr(pos[i] + 1, (int) s.size() - pos[i] - 1) + ")";
		ans = max(ans, evaluate(temp));
		for (int j = i + 1; j < (int) pos.size(); j++) {
			temp = s.substr(0, pos[i] + 1) + "("
					+ s.substr(pos[i] + 1, pos[j] - pos[i] - 1) + ")"
					+ s.substr(pos[j], (int) s.size() - pos[j]);
			ans = max(ans, evaluate(temp));
		}
	}
	cout << ans << endl;
	return 0;
}
