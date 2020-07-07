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


class BigFatInteger2 {
public:
	string isDivisible(int A, int B, int C, int D) {
		map<long long,long long> a,c;
		map<long long,long long>::iterator it;
		long long cnt,first,second,i=2;
		while(A>1 && i*i<=A){
            cnt=0;
            while(A%i==0){
                cnt++;
                A/=i;
            }
            a[i]=cnt*B;
            i++;
		}
		if(A>1)
            a[A]+=B;
		i=2;
		while(C>1 && i*i<=C){
            cnt=0;
            while(C%i==0){
                cnt++;
                C/=i;
            }
            c[i]=cnt*D;
            i++;
		}
		if(C>1)
            c[C]+=D;
		for(it=c.begin();it!=c.end();it++){
            first=it->first;
            second=it->second;
            if(second>a[first])
                return "not divisible";
		}
        return "divisible";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, string p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	BigFatInteger2 *obj;
	string answer;
	obj = new BigFatInteger2();
	clock_t startTime = clock();
	answer = obj->isDivisible(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p4 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	string p4;

	{
	// ----- test 0 -----
	p0 = 6;
	p1 = 1;
	p2 = 2;
	p3 = 1;
	p4 = "divisible";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 1;
	p2 = 6;
	p3 = 1;
	p4 = "not divisible";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 1000000000;
	p1 = 1000000000;
	p2 = 1000000000;
	p3 = 200000000;
	p4 = "divisible";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 8;
	p1 = 100;
	p2 = 4;
	p3 = 200;
	p4 = "not divisible";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 999999937;
	p1 = 1000000000;
	p2 = 999999929;
	p3 = 1;
	p4 = "not divisible";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = 2;
	p1 = 2;
	p2 = 4;
	p3 = 1;
	p4 = "divisible";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
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