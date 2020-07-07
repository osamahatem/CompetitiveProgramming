/*
 * B. Curvy Little Bottles.cpp
 *
 *  Created on: Feb 18, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

typedef long double myf;

const myf EPS = 1e-9;
const myf PI = acosl(-1.0L);

int n, inc;
myf in[11], P[22], xl, xh;

myf func(myf x) {
	myf ret = 0.0L, p = x;
	for (int i = 0; i <= n + n; i++) {
		ret += P[i] * p / (i + 1);
		p *= x;
	}
	return ret;
}

myf integrate(myf a, myf b) {
	return (func(b) - func(a)) * PI;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(2);

	int T = 0;
	while (cin >> n) {
		for (int i = 0; i <= n; i++)
			cin >> in[i];
		cin >> xl >> xh >> inc;

		for (int i = 0; i <= n + n; i++)
			P[i] = 0.0L;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				P[i + j] += in[i] * in[j];

		myf vol = integrate(xl, xh);
		cout << "Case " << ++T << ": " << vol << endl;
		for (int i = 1, cur = inc; i < 9 && cur < vol; i++, cur += inc) {
			myf s = xl, e = xh;
			for (myf sz = (e - s) / 2.0L; sz > EPS; sz *= 0.5L) {
				myf mid = s + sz;
				if (integrate(xl, mid) < cur)
					s += sz;
			}
			if (i > 1)
				cout << " ";
			cout << s - xl;
		}
		if (inc > vol - EPS)
			cout << "insufficient volume";
		cout << endl;
	}
	return 0;
}
