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

char t[2000000];

bool isValid(int n,char par){
    if(n>(1<<20))
        return true;
    if(t[n]==0)
        return isValid(n*2,par)&isValid(n*2+1,par);
    if(t[n]=='?'){
        if(n%2==0)
            par++;
        return isValid(n*2,par)&isValid(n*2+1,par);
    }
    if(n>1){
        if(n%2==0 && t[n]>par)
            return false;
        if(n%2 && t[n]<=par)
            return false;
    }
    return isValid(n*2,t[n])&isValid(n*2+1,t[n]);
}

class IncompleteBST {
public:
	string missingValues(vector <string> tree) {
	    memset(t,0,sizeof t);
		char c;
		int i,x;
		string ret="";
		for(i=0;i<tree.size();i++){
            sscanf(tree[i].c_str(),"%c %d",&c,&x);
            t[x]=c;
		}
		if(!isValid(1,0))
            return ret;
        return "A";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	IncompleteBST *obj;
	string answer;
	obj = new IncompleteBST();
	clock_t startTime = clock();
	answer = obj->missingValues(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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

	vector <string> p0;
	string p1;

	{
	// ----- test 0 -----
	string t0[] = {"A 1","? 2"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "A";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {"B 1","? 2"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "AB";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {"V 1","? 3"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "WXYZ";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	string t0[] = {"K 1","K 2","A 6","? 12","Y 3"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	string t0[] = {"Z 1","Y 2","X 4","W 8","V 16","U 32","T 64","S 128","R 256","Q 512","P 1024","O 2048","N 4096","M 8192","L 16384","K 32768","J 65536","? 131072"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "ABCDEFGHIJ";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
