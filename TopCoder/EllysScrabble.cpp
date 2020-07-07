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
#include <cstring>
#include <ctime>

using namespace std;


class EllysScrabble {
public:
	string getMin(string letters, int maxDistance) {
	    bool used[55];
	    memset(used,0,sizeof used);
	    int idx;
	    char x;
	    string ans="";
	    for(int i=0;i<letters.size();i++){
            int start=max(0,i-maxDistance),end=min((int)letters.size()-1,i+maxDistance);
            x='Z'+1;
            if(!used[start] && start==i-maxDistance){
                used[start]=1;
                ans+=letters[start];
                continue;
            }
            for(int j=start;j<=end;j++){
                if(used[j])
                    continue;
                if(letters[j]<x){
                    x=letters[j];
                    idx=j;
                }
            }
            used[idx]=1;
            ans+=x;
	    }
	    return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1;
	cout << "]" << endl;
	EllysScrabble *obj;
	string answer;
	obj = new EllysScrabble();
	clock_t startTime = clock();
	answer = obj->getMin(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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

	string p0;
	int p1;
	string p2;

	{
	// ----- test 0 -----
	p0 = "TOPCODER";
	p1 = 3;
	p2 = "CODTEPOR";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = "ESPRIT";
	p1 = 3;
	p2 = "EIPRST";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = "BAZINGA";
	p1 = 8;
	p2 = "AABGINZ";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	p1 = 9;
	p2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = "GOODLUCKANDHAVEFUN";
	p1 = 7;
	p2 = "CADDGAHEOOFLUKNNUV";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
	p1 = 6;
	p2 = "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 6 -----
	p0 = "ABRACADABRA";
	p1 = 2;
	p2 = "AABARACBDAR";
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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
