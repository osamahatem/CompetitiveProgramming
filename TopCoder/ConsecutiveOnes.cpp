/*
 * ConsecutiveOnes.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

class ConsecutiveOnes {
public:
	long long get(long long n, int k) {
		long long mask = (1ll << k) - 1;
		long long ret = (1ll << 50) - 1;
		for (int i = 0; i <= 50 - k; mask <<= 1, i++) {
			long long temp = mask | n;
			if (temp > n)
				temp &= (~((1ll << i) - 1));
			ret = min(ret, temp);
		}
		return ret;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	ConsecutiveOnes* x = new ConsecutiveOnes();
	cout << x->get(364269800189924, 33) << endl;
	return 0;
}
