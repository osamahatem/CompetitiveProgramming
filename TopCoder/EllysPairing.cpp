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


class EllysPairing {
public:
	int getMax(int M, vector <int> count, vector <int> first, vector <int> mult, vector <int> add) {
	    int cnt=0,i,j,maj,sum=0;
	    unsigned int x,last;
	    for(i=0;i<add.size();i++){
            sum+=count[i];
            if(cnt==0)
                maj=first[i];
            if(first[i]==maj)
                cnt++;
            else
                cnt--;
            last=first[i];
            for(j=1;j<count[i];j++){
                x=(last*mult[i]+add[i])&(M-1);
                if(cnt==0)
                    maj=x;
                if(x==maj)
                    cnt++;
                else
                    cnt--;
                last=x;
            }
	    }
	    cnt=0;
	    for(i=0;i<add.size();i++){
            if(first[i]==maj)
                cnt++;
            last=first[i];
            for(j=1;j<count[i];j++){
                x=(last*mult[i]+add[i])&(M-1);
                if(x==maj)
                    cnt++;
                last=x;
            }
	    }
	    if(sum%2) cnt--;
        int ret=max(0,cnt-sum/2);
        return sum/2-ret;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, vector <int> p3, vector <int> p4, bool hasAnswer, int p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p4.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p4[i];
	}
	cout << "}";
	cout << "]" << endl;
	EllysPairing *obj;
	int answer;
	obj = new EllysPairing();
	clock_t startTime = clock();
	answer = obj->getMax(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	vector <int> p4;
	int p5;

	{
	// ----- test 0 -----
	p0 = 16;
	int t1[] = {4,7};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {5,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {2,3};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {1,0};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 5;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 8;
	int t1[] = {6,4,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,3,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {3,7,5};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,3,2};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 5;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 128;
	int t1[] = {42,13,666,17,1337,42,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {18,76,3,122,0,11,11};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {33,17,54,90,41,122,20};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {66,15,10,121,122,1,30};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 1059;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 1048576;
	int t1[] = {4242,42,9872,13,666,21983,17,1337,42,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {19,18,76,42,3,112,0,11,11,12};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {27,33,10,8,17,9362,90,41,122,20};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {98,101,66,15,10,144,3,1,5,1};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 16232;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 1073741824;
	int t1[] = {894602,946569,887230,856152,962583,949356,904847,829100,842183,958440,811081,864078,809209,938727,949135,892809,816528,961237,979142,890922};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {844085078,898937259,243490172,887804102,187696417,156820442,237600210,618812924,153000239,912364033,254936966,650298774,982988140,649258331,566444626,201481721,492943390,1061953081,492672963,960519711};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1036482037,583219072,819168094,253755052,548208982,401830167,638626082,43642932,123607749,485521178,860368129,30334704,219771462,733375600,130839219,415503960,294132484,1044831462,256910484,198852170};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {889169006,604831366,967292994,980686280,844875791,1027687492,357734882,295879743,48284748,421729100,1049536313,327207332,948053446,271229570,664579359,795815285,842856528,876662975,675611938,634229925};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 8971965;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
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