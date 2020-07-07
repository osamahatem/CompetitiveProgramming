/*
 * 2722 - Light Bulbs.cpp
 *
 *  Created on: Dec 21, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 405;

vector<int> src, dest;
int dp[MAXN][2][2][2];

string div2(string x) {
	string ret = "";
	bool carry = 0;
	for (int i = 0; i < (int) x.size(); i++) {
		int d = x[i] - '0';
		int r = d / 2 + (carry ? 5 : 0);
		carry = d & 1;
		if (r || i)
			ret += (char) ('0' + r);
	}
	if (ret.empty())
		ret = "0";
	return ret;
}

string mul2(string x) {
	string ret = "";
	int carry = 0;
	reverse(x.begin(), x.end());
	for (int i = 0; i < (int) x.size(); i++) {
		int d = x[i] - '0';
		int r = d * 2 + carry;
		carry = r / 10;
		r %= 10;
		ret += (char) ('0' + r);
	}
	if (carry)
		ret += '1';
	reverse(ret.begin(), ret.end());
	return ret;
}

string add1(string x) {
	bool carry = 1;
	for (int i = (int) x.size() - 1; carry && ~i; i--) {
		x[i]++;
		if (x[i] > '9')
			x[i] = '0', carry = 1;
		else
			carry = 0;
	}
	if (carry)
		x = "1" + x;
	return x;
}

vector<int> decToBin(string x) {
	vector<int> ret;
	do {
		ret.push_back(x.back() & 1);
		x = div2(x);
	} while (x != "0");
	reverse(ret.begin(), ret.end());
	return ret;
}

string binToDec(vector<int> x) {
	string ret = "0";
	for (auto d : x) {
		ret = mul2(ret);
		if (d)
			ret = add1(ret);
	}
	return ret;
}

bool check(int idx, bool a, bool tog) {
	a ^= tog;
	bool aa = (idx ? dest[idx - 1] : a);
	return a == aa;
}

int solve(int idx, bool a, bool b, bool c) {
	if (idx == (int) src.size())
		return (dest[idx - 1] == a ? 0 : MAXN);
	int &ret = dp[idx][a][b][c];
	if (~ret)
		return ret;
	ret = MAXN;
	if (check(idx, a, 0))
		ret = min(ret,
				solve(idx + 1, b, c,
						(idx + 2 < (int) src.size() ? src[idx + 2] : 0)));
	if (check(idx, a, 1))
		ret = min(ret,
				solve(idx + 1, !b, !c,
						(idx + 2 < (int) src.size() ? src[idx + 2] : 0)) + 1);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t = 0;
	string a, b;
	while (cin >> a >> b, a != "0" || b != "0") {
		src = decToBin(a), dest = decToBin(b);
		while (src.size() < dest.size())
			src.insert(src.begin(), 0);
		while (dest.size() < src.size())
			dest.insert(dest.begin(), 0);

		if (t)
			cout << endl;
		cout << "Case Number " << ++t << ": ";

		memset(dp, -1, sizeof dp);
		int ans = solve(0, 0, src[0], src.size() > 1 ? src[1] : 0);
		if (ans >= MAXN) {
			cout << "impossible" << endl;
			continue;
		}
		vector<int> temp;
		bool a = 0, b = src[0], c = src.size() > 1 ? src[1] : 0;
		for (int i = 0; i < (int) src.size(); i++) {
			bool nxt = i + 2 < (int) src.size() ? src[i + 2] : 0;
			if (check(i, a, 0) && solve(i + 1, b, c, nxt) == dp[i][a][b][c]) {
				temp.push_back(0);
				a = b;
				b = c;
				c = nxt;
			} else {
				temp.push_back(1);
				a = !b;
				b = !c;
				c = nxt;
			}
		}
		cout << binToDec(temp) << endl;
	}
	return 0;
}
