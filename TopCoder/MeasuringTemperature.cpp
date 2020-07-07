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

vector<int> temp;

bool valid(int idx){
    if(temp[idx]<-273)
        return false;
    int cnt=0,len=0;
    for(int i=max(0,idx-2);i<=min(idx+2,(int)temp.size()-1);i++){
        if(i==idx)
            continue;
        if(abs(temp[idx]-temp[i])>2)
            cnt++;
        len++;
    }
    if(cnt==len)
        return false;
    return true;
}

class MeasuringTemperature {
public:
	double averageTemperature(vector <int> measuredValues) {
		temp=measuredValues;
		int cnt=0;
		double sum=0.0;
		for(int i=0;i<measuredValues.size();i++){
            if(valid(i)){
                cnt++;
                sum+=measuredValues[i];
            }
		}
		if(cnt==0)
            return -300.0;
        return sum/cnt;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, double p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	MeasuringTemperature *obj;
	double answer;
	obj = new MeasuringTemperature();
	clock_t startTime = clock();
	answer = obj->averageTemperature(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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

	vector <int> p0;
	double p1;

	{
	// ----- test 0 -----
	int t0[] = {9,11,12,13,15};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 12.0;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {0,0,0,2,997,-1,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0.16666666666666666;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	int t0[] = {0,0,0,2,-4,-1,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0.16666666666666666;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {0,0,0,2,-3,-1,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -0.2857142857142857;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	int t0[] = {1,2,3,100,100,1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 29.857142857142858;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	int t0[] = {1,2,3,4,5,6,7,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4.0;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 6 -----
	int t0[] = {-35,-34,-34,-34,-35,72,-34,52,-36,-35,-36,52,-36,-35,981,-33};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -34.75;
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 7 -----
	int t0[] = {-273,-273,-274,-273};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -273.0;
	all_right = KawigiEdit_RunTest(7, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 8 -----
	int t0[] = {10,20,30,40};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -300.0;
	all_right = KawigiEdit_RunTest(8, p0, true, p1) && all_right;
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