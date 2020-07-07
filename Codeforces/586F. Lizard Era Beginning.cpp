/*
 *  586F. Lizard Era Beginning
 *
 *  Created on: Oct 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct conf {
	int a, b, c, tot, id;

	const bool operator <(const conf &other) const {
		if (a != other.a)
			return a < other.a;
		if (b != other.b)
			return b < other.b;
		if (c != other.c)
			return c < other.c;
		return tot < other.tot;
	}
};

int arr[25][3];
string out[3] = { "LM", "LW", "MW" };

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	int n1 = (n + 1) / 2, n2 = n - n1, p1 = 1, p2 = 1;
	for (int i = 0; i < n1; i++)
		p1 *= 3;
	for (int i = 0; i < n2; i++)
		p2 *= 3;
	vector<conf> v1, v2;
	for (int i = 0; i < p1; i++) {
		int mask = i;
		conf temp;
		temp.id = mask, temp.a = 0, temp.b = 0, temp.c = 0;
		for (int j = 0; j < n1; j++) {
			int cur = mask % 3;
			mask /= 3;
			if (cur == 0 || cur == 1)
				temp.a += arr[j][0];
			if (cur == 0 || cur == 2)
				temp.b += arr[j][1];
			if (cur == 1 || cur == 2)
				temp.c += arr[j][2];
		}
		temp.tot = temp.a;
		int maxi = max(temp.a, max(temp.b, temp.c));
		temp.a = maxi - temp.a;
		temp.b = maxi - temp.b;
		temp.c = maxi - temp.c;
		v1.push_back(temp);
	}
	for (int i = 0; i < p2; i++) {
		int mask = i;
		conf temp;
		temp.id = mask, temp.a = 0, temp.b = 0, temp.c = 0;
		for (int j = 0; j < n2; j++) {
			int cur = mask % 3;
			mask /= 3;
			if (cur == 0 || cur == 1)
				temp.a += arr[n1 + j][0];
			if (cur == 0 || cur == 2)
				temp.b += arr[n1 + j][1];
			if (cur == 1 || cur == 2)
				temp.c += arr[n1 + j][2];
		}
		temp.tot = temp.a;
		int mini = min(temp.a, min(temp.b, temp.c));
		temp.a -= mini;
		temp.b -= mini;
		temp.c -= mini;
		v2.push_back(temp);
	}
	sort(v2.begin(), v2.end());
	int ans = -(1 << 30), m1 = 0, m2 = 0;
	for (int i = 0; i < p1; i++) {
		conf temp = v1[i];
		temp.tot = 1 << 30;
		int idx = upper_bound(v2.begin(), v2.end(), temp) - v2.begin() - 1;
		if (idx >= 0 && v2[idx].a == temp.a && v2[idx].b == temp.b
				&& v2[idx].c == temp.c && v1[i].tot + v2[idx].tot > ans)
			ans = v1[i].tot + v2[idx].tot, m1 = v1[i].id, m2 = v2[idx].id;
	}
	if (ans == -(1 << 30)) {
		cout << "Impossible" << endl;
		return 0;
	}
	for (int i = 0; i < n1; i++) {
		cout << out[m1 % 3] << endl;
		m1 /= 3;
	}
	for (int i = 0; i < n2; i++) {
		cout << out[m2 % 3] << endl;
		m2 /= 3;
	}
	return 0;
}
