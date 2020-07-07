/*
 * 713B. Searching Rectangles.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

void check(int x11, int y11, int x12, int y12, int x21, int y21, int x22,
		int y22) {
	if (x12 < x11 || y12 < y11 || x22 < x21 || y22 < y21)
		return;
	int r;
	cout << "? " << x11 << " " << y11 << " " << x12 << " " << y12 << endl;
	cin >> r;
	if (r != 1)
		return;
	cout << "? " << x21 << " " << y21 << " " << x22 << " " << y22 << endl;
	cin >> r;
	if (r != 1)
		return;
	cout << "! " << x11 << " " << y11 << " " << x12 << " " << y12 << " ";
	cout << x21 << " " << y21 << " " << x22 << " " << y22 << endl;
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, r, s, e, one = 1;
	cin >> n;
	int x1[2], x2[2], y1[2], y2[2];

	// x1[0]
	s = 1, e = n;
	while (s < e) {
		int mid = (s + e + 1) / 2;
		cout << "? " << mid << " " << one << " " << n << " " << n << endl;
		cin >> r;
		if (r == 2)
			s = mid;
		else
			e = mid - 1;
	}
	x1[0] = s;

	// x1[1]
	s = 1, e = n;
	while (s < e) {
		int mid = (s + e + 1) / 2;
		cout << "? " << mid << " " << one << " " << n << " " << n << endl;
		cin >> r;
		if (r == 0)
			e = mid - 1;
		else
			s = mid;
	}
	x1[1] = s;

	// x2[0]
	s = 1, e = n;
	while (s < e) {
		int mid = (s + e) / 2;
		cout << "? " << one << " " << one << " " << mid << " " << n << endl;
		cin >> r;
		if (r == 0)
			s = mid + 1;
		else
			e = mid;
	}
	x2[0] = s;

	// x2[1]
	s = 1, e = n;
	while (s < e) {
		int mid = (s + e) / 2;
		cout << "? " << one << " " << one << " " << mid << " " << n << endl;
		cin >> r;
		if (r == 2)
			e = mid;
		else
			s = mid + 1;
	}
	x2[1] = s;

	// y1[0]
	s = 1, e = n;
	while (s < e) {
		int mid = (s + e + 1) / 2;
		cout << "? " << one << " " << mid << " " << n << " " << n << endl;
		cin >> r;
		if (r == 2)
			s = mid;
		else
			e = mid - 1;
	}
	y1[0] = s;

	// y1[1]
	s = 1, e = n;
	while (s < e) {
		int mid = (s + e + 1) / 2;
		cout << "? " << one << " " << mid << " " << n << " " << n << endl;
		cin >> r;
		if (r == 0)
			e = mid - 1;
		else
			s = mid;
	}
	y1[1] = s;

	// y2[0]
	s = 1, e = n;
	while (s < e) {
		int mid = (s + e) / 2;
		cout << "? " << one << " " << one << " " << n << " " << mid << endl;
		cin >> r;
		if (r == 0)
			s = mid + 1;
		else
			e = mid;
	}
	y2[0] = s;

	// y2[1]
	s = 1, e = n;
	while (s < e) {
		int mid = (s + e) / 2;
		cout << "? " << one << " " << one << " " << n << " " << mid << endl;
		cin >> r;
		if (r == 2)
			e = mid;
		else
			s = mid + 1;
	}
	y2[1] = s;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				for (int l = 0; l < 2; l++)
					check(x1[i], y1[j], x2[k], y2[l], x1[1 - i], y1[1 - j],
							x2[1 - k], y2[1 - l]);
	return 0;
}
