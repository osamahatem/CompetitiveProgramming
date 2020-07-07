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

using namespace std;


class CoinsExchange {
public:
	int countExchanges(int G1, int S1, int B1, int G2, int S2, int B2) {
	    int ret=0;
	    while(G1<G2){
            if(S1>=11) S1-=11,G1++,ret++;
            else if(B1>=11) B1-=11,S1++,ret++;
            else return -1;
	    }
	    while(S1<S2){
            if(G1>G2) G1--,S1+=9,ret++;
            else if(B1>=11) B1-=11,S1++,ret++;
            else return -1;
	    }
	    while(B1<B2){
            if(S1>S2) S1--,B1+=9,ret++;
            else if(G1>G2) G1--,S1+=9,ret++;
            else return -1;
	    }
	    return ret;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, int p5, bool hasAnswer, int p6) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5;
	cout << "]" << endl;
	CoinsExchange *obj;
	int answer;
	obj = new CoinsExchange();
	clock_t startTime = clock();
	answer = obj->countExchanges(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p6 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p6;
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
	int p4;
	int p5;
	int p6;

	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 0;
	p2 = 0;
	p3 = 0;
	p4 = 0;
	p5 = 81;
	p6 = 10;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 100;
	p2 = 12;
	p3 = 5;
	p4 = 53;
	p5 = 33;
	p6 = 7;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 100;
	p2 = 12;
	p3 = 5;
	p4 = 63;
	p5 = 33;
	p6 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 5;
	p1 = 10;
	p2 = 12;
	p3 = 3;
	p4 = 7;
	p5 = 9;
	p6 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!