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

class InverseRMQ {
public:
	string possible(int n, vector <int> A, vector <int> B, vector <int> ans) {
	    set<int> vis;
        vector< pair<int,int> > events;
        for(int i=0;i<A.size();i++){
            if(A[i]==1 && B[i]==n && ans[i]!=n)
                return "Impossible";
            events.push_back(make_pair(A[i],ans[i]));
            events.push_back(make_pair(B[i],-1));
        }
        sort(events.begin(),events.end());
        stack<int> maxi;
        bool flag=0;
        for(int i=0;i<events.size();i++){
            if(events[i].second==-1){
                if(maxi.size()){
                    vis.insert(maxi.top());
                    maxi.pop();
                }else
                    flag=1;
                continue;
            }
            printf("%d ",events[i].second);
            if(maxi.size() && !flag && (events[i].second>maxi.top() || events[i].second>n || vis.count(events[i].second)))
                return "Impossible";
            if(!flag)
                maxi.push(events[i].second);
            else
                vis.insert(events[i].second);
            flag=0;
        }
        return "Possible";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, string p4) {
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
	cout << "}";
	cout << "]" << endl;
	InverseRMQ *obj;
	string answer;
	obj = new InverseRMQ();
	clock_t startTime = clock();
	answer = obj->possible(p0, p1, p2, p3);
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
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	string p4;

	{
	// ----- test 0 -----
	p0 = 5;
	int t1[] = {1,2,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,4,5};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {3,4,5};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = "Possible";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 3;
	int t1[] = {1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {3,3,3};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = "Impossible";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 600;
	int t1[] = {1,101,201,301,401,501};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {100,200,300,400,500,600};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {100,200,300,400,500,600};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = "Possible";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 1000000000;
	int t1[] = {1234,1234};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {5678,5678};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {10000,20000};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = "Impossible";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 8;
	int t1[] = {1,2,3,4,5,6,7,8};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,3,4,5,6,7,8};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {4,8,2,5,6,3,7,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = "Possible";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = 1000000000;
	int t1[] = {1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1000000000};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {19911120};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = "Impossible";
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