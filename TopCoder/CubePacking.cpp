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
#include <climits>

using namespace std;

class CubePacking {
public:
	int getMinimumVolume(int Ns, int Nb, int L) {
		int bVol = L * L * L;
		int maxi = (Nb + Ns / bVol + (bool) (Ns % bVol)) * bVol, ans = 1;
		for (int i = 1; i * i * i <= maxi; i++)
			ans++;
		maxi = ans * ans * ans;
		ans = maxi;
		for (int x = L; x * x * x <= maxi; x++) {
			for (int y = x; y * y <= maxi / x; y++) {
				int bx = x / L, by = y / L;
				int bz = Nb / (bx * by) + (bool) (Nb % (bx * by));
				int z = bz * L;
				if (z > maxi / (x * y))
					continue;
				int left = x * y * z - Nb * bVol;
				if (Ns > left)
					z += (Ns - left) / (x * y) + (bool) ((Ns - left) % (x * y));
				ans = min(ans, x * y * z);
			}
		}
		return ans;
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer,
		int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	CubePacking *obj;
	int answer;
	obj = new CubePacking();
	clock_t startTime = clock();
	answer = obj->getMinimumVolume(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC
			<< " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	int p3;

	{
		// ----- test 0 -----
		p0 = 2;
		p1 = 2;
		p2 = 2;
		p3 = 20;
		all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = 19;
		p1 = 1;
		p2 = 2;
		p3 = 27;
		all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = 51;
		p1 = 7;
		p2 = 5;
		p3 = 950;
		all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		p0 = 12345;
		p1 = 987;
		p2 = 10;
		p3 = 999400;
		all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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
