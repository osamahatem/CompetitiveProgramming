/*
 * CIVIL - ternary search + integration.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Osama Hatem
 */
 
/*
We can work only on the +ve half of the mountain; it is symmetrical, and if we
assume it is centred at x = 0, we can get the value of c in f(x) =
ax^2 + bx + c. Given the information that the mountain is horizontal where it
touches the ground, we can solve f(w / 2) = 0 and f'(w / 2) = 0 to get a and b.
To calculate the cost, we need to be able to compute the length of the curve
between 2 given points. Refer to this link for a tutorial on how to do it with
integration:
https://www.khanacademy.org/math/multivariable-calculus/integrating-multivariable-functions/line-integrals-for-scalar-functions-articles/a/arc-length
The cost at a given x is f * x (x is the length of the tunnel, and f is the
factor described in the problem statement) + the curve length between x and
w / 2. We need to integrate the curve length formula by hand and hardcode it
because using Simpson's method or any similar method is slow and inaccurate for
this problem.
Now we can perform a ternary search on the x that will minimise the cost, and
the answer will be f(x) for that x.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

typedef long double myf;

const myf EPS = 1e-15;

myf a, b, c, h, w, f;

myf fun(myf x) {
	return 2.0L * a * x + b;
}

myf integral(myf x) {
	myf v = fun(x);
	myf ret = (v * sqrtl(1.0L + v * v) + asinhl(v)) / (4.0L * a);
	return ret;
}

myf check(myf x) {
	return integral(w / 2.0L) - integral(x) + f * x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(3);

	while (cin >> h >> w >> f, h > EPS || w > EPS || f > EPS) {
		c = h;
		b = -4.0L * h / w;
		a = -b / w;

		myf s = 0.0L;
		for (myf sz = w / 6.0L; sz > EPS; sz *= 2.0L / 3.0L) {
			myf m1 = s + sz, m2 = s + sz + sz;
			if (check(m2) < check(m1) - EPS)
				s += sz;
		}
		cout << a * s * s + b * s + c << endl;
	}
	return 0;
}
