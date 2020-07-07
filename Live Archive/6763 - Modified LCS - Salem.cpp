/*
 * 6763 - Modified LCS.cpp
 *
 *  Created on: Aug 27, 2016
 *      Author: Ahmed Salem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int LOWER = 0;
const int UPPER = 1;

typedef long long LL;

class ExtendedEuclid {
public:
	// no guarantees on the sign of g if A and B have different signs
	// should manually check if C % g != 0
	long long A, B, C;
	long long g, x, y;
	ExtendedEuclid(long long A, long long B, long long C) :
			A(A), B(B), C(C) {
		run(A, B, g, x, y);
		x *= C / g;
		y *= C / g;
	}
	long long getK(long long limit, bool type, long long B, long long x) {
		long long num = limit - x;
		long long den = B;
		type ^= num > 0;
		int sign = 1 + -2 * ((num < 0) ^ (den < 0));
		num = abs(num);
		den = abs(den);
		long long ret = (num + type * (den - 1)) / den;
		return sign * ret;
	}
	long long getKforA(long long limit, bool type) {
		return getK(limit, type, B / g, x);
	}
	long long getKforB(long long limit, bool type) {
		return -getK(limit, type, A / g, y);
	}
	long long getX(long long k) {
		return x + B / g * k;
	}
	long long getY(long long k) {
		return y - A / g * k;
	}
	bool isKIncForA() {
		return getX(1) >= x;
	}
	bool isKIncForB() {
		return getY(1) >= y;
	}
private:
	void run(long long a, long long b, long long& g, long long& x,
			long long& y) {
		if (!b) {
			g = a;
			x = 1;
			y = 0;
			return;
		}
		long long xNext, yNext;
		run(b, a % b, g, xNext, yNext);
		x = yNext;
		y = xNext - (a / b) * yNext;
		return;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int c, c2;
	int T;
	scanf("%d", &T);
	while (T--) {
		int f1, d1, f2, d2;
		long long n1, n2;
		scanf("%lld%d%d%lld%d%d", &n1, &f1, &d1, &n2, &f2, &d2);
		ExtendedEuclid euclid(d1, -d2, f2 - f1);
		if (euclid.C % euclid.g) {
			printf("0\n");
		} else {
			pair<LL, LL> range1 = { euclid.getKforA(0, LOWER), euclid.getKforA(
					n1 - 1, UPPER) };
			if (!euclid.isKIncForA())
				swap(range1.first, range1.second);
			pair<LL, LL> range2 = { euclid.getKforB(0, LOWER), euclid.getKforB(
					n2 - 1, UPPER) };
			if (!euclid.isKIncForB())
				swap(range2.first, range2.second);
			range1.first = max(range1.first, range2.first);
			range1.second = min(range1.second, range2.second);
			printf("%lld\n", max(0LL, range1.second - range1.first + 1));
		}
	}

	return 0;
}
