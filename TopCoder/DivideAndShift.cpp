#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

vector<pair<int, int> > primes;

int memo[1000005];

int solve(int N, int M) {
	if (M == 0)
		return 0;

	int &ret = memo[N];
	if (ret != -1)
		return ret;

	ret = min(M, N - M);
	for (int i = 0; i < (int) primes.size(); i++) {
		if (primes[i].second == 0)
			continue;

		primes[i].second--;
		ret = min(ret,
				1 + solve(N / primes[i].first, M % (N / primes[i].first)));
		primes[i].second++;
	}
	return ret;
}

class DivideAndShift {
public:
	int getLeast(int N, int M) {
		primes.clear();
		int t = N;
		for (int i = 2; i <= t / i; i++) {
			int c = 0;
			while (t % i == 0) {
				c++;
				t /= i;
			}
			if (c)
				primes.push_back(make_pair(i, c));
		}
		if (t > 1)
			primes.push_back(make_pair(t, 1));

		memset(memo, -1, sizeof memo);
		return solve(N, --M);
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	DivideAndShift *obj;
	int answer;
	obj = new DivideAndShift();
	clock_t startTime = clock();
	answer = obj->getLeast(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC
			<< " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	int p1;
	int p2;

	{
		// ----- test 0 -----
		p0 = 56;
		p1 = 14;
		p2 = 3;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = 49;
		p1 = 5;
		p2 = 2;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = 256;
		p1 = 7;
		p2 = 6;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		p0 = 6;
		p1 = 1;
		p2 = 0;
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		p0 = 77777;
		p1 = 11111;
		p2 = 2;
		all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
		// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!