/*
 * CIVIL - formula.cpp
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
w / 2.
To get the optimal x, we can calculate the derivative of the cost function
described above and equate it to zero. This derivation will also cancel out the
integration in the cost function and we won't need to evaluate it. We will be
left with a quadratic equation whose coefficients are expressed in terms of a
and b calculated above, and the factor f provided in the input. We can easily
solve this equation using the well-know quadratic formula.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

typedef long double myf;

const myf EPS = 1e-15;

myf a, b, c, h, w, f;

myf solve(myf a, myf b, myf c) {
	myf temp = sqrtl(b * b - 4.0L * a * c);
	myf ret = (-b + temp) / (2.0L * a);
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
	cout << fixed << setprecision(3);

	while (cin >> h >> w >> f, h > EPS || w > EPS || f > EPS) {
		c = h;
		b = -4.0L * h / w;
		a = -b / w;

		myf s = solve(4.0L * a * a, 4.0L * a * b, b * b - f * f + 1.0L) + EPS;
		cout << a * s * s + b * s + c << endl;
	}
	return 0;
}
