/*
 * 2726 - Combining Images.cpp
 *
 *  Created on: Dec 23, 2017
 *      Author: Osama Hatem
 */
 
/*
Iterate over both encodings simultaneously, applying the combining operation
accordingly. I used recursion to isolate sub-problems for easier thinking and
implementation. Note that this process can produce invalid encodings: identical
homogeneous sub-quadrants must be combined.
*/

#include <bits/stdc++.h>
#include <ext/numeric>

using namespace std;

const string HEX = "0123456789ABCDEF";
const string BIN[16] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110",
		"0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };

string A, B;

string binToHex(string x) {
	string ret = "";
	while (x.size() % 4)
		x = "0" + x;
	for (int i = 0; i < (int) x.size(); i += 4) {
		int idx = find(BIN, BIN + 16, x.substr(i, 4)) - BIN;
		ret += HEX[idx];
	}
	return ret;
}

string hexToBin(string x) {
	string ret = "";
	for (int i = 0; i < (int) x.size(); i++) {
		int idx = HEX.find(x[i]);
		ret += BIN[idx];
	}
	return ret;
}

string solve(int &i, int &j, int d1, int d2) {
	string ret = "";
	if (d1 < d2) {
		if (B[j] == '1') {
			j++;
			ret = B[j] == '0' ? "10" : "11";
			j++;
		} else {
			j++;
			ret = "0";
			for (int k = 0; k < 4; k++)
				ret += solve(i, j, d1, d2 + 1);
		}
	} else if (d1 > d2) {
		if (A[i] == '1') {
			i++;
			ret = A[i] == '0' ? "10" : "11";
			i++;
		} else {
			i++;
			ret = "0";
			for (int k = 0; k < 4; k++)
				ret += solve(i, j, d1 + 1, d2);
		}
	} else {
		if (A[i] == '1' && B[j] == '1') {
			i++, j++;
			ret = A[i] == '0' || B[j] == '0' ? "10" : "11";
			i++, j++;
		} else if (A[i] == '0' && B[j] == '0') {
			i++, j++;
			ret = "0";
			for (int k = 0; k < 4; k++)
				ret += solve(i, j, d1 + 1, d2 + 1);
		} else if (A[i] == '0' && B[j] == '1') {
			i++, j++;
			ret = "0";
			for (int k = 0; k < 4; k++)
				ret += solve(i, j, d1 + 1, d2);
			if (B[j] == '0')
				ret = "10";
			j++;
		} else {
			i++, j++;
			ret = "0";
			for (int k = 0; k < 4; k++)
				ret += solve(i, j, d1, d2 + 1);
			if (A[i] == '0')
				ret = "10";
			i++;
		}
	}
	if (ret[0] == '0' && ret.substr(1, 8) == "10101010")
		ret = "10";
	else if (ret[0] == '0' && ret.substr(1, 8) == "11111111")
		ret = "11";
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
	while (cin >> A >> B, A != "0") {
		A = hexToBin(A);
		B = hexToBin(B);
		int i = 0, j = 0;
		for (; A[i] == '0'; i++)
			;
		for (; B[j] == '0'; j++)
			;
		i++, j++;
		if (t)
			cout << endl;
		cout << "Image " << ++t << ":" << endl;
		cout << binToHex("1" + solve(i, j, 0, 0)) << endl;
	}
	return 0;
}
