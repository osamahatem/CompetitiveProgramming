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

struct sol{double sub,water;};

class MixingLiquids {
public:
	double howMuch(vector <int> percent, vector <int> amount, int need) {
        sol lower,higher;
        lower.sub=higher.sub=lower.water=higher.water=0.0;
        int i;
        double ret=0.0;
        for(i=0;i<amount.size();i++){
            if(percent[i]==need)
                ret+=amount[i];
            else if(percent[i]<need){
                lower.sub=amount[i]*percent[i]/100.0;
                lower.water=(double)amount[i]-lower.sub;
            }else{
                higher.sub=amount[i]*percent[i]/100.0;
                higher.water=(double)amount[i]-lower.sub;
            }
        }
        double lo1=0.0,hi1=lower.sub+lower.water,mid1,ans=0.0;
        while(lo1<hi1){
            mid1=(lo1+hi1)/2.0;
            double per=lower.sub/(lower.sub+lower.water);
            double sub_t=mid1*per,water_t=mid1-sub_t;
            double lo2=0.0,hi2=higher.sub+higher.water,mid2,ans_t;
            bool flag=0;
            while(lo2<hi2){
                mid2=(lo2+hi2)/2.0;
                double per2=higher.sub/(higher.sub+higher.water);
                double sub_t2=mid2*per2,water_t2=mid2-sub_t2,total_sub,total_water,total_per;
                total_sub=sub_t+sub_t2,total_water=water_t+water_t2;
                total_per=total_sub/(total_sub+total_water);
                if(fabs((double)need-total_per)<1e-9){
                    ans_t=total_sub+total_water;
                    flag=1;
                    break;
                }else if(total_per<(double)need)
                    lo2=mid2;
                else
                    hi2=mid2;
            }
            if(flag){
                ans=ans_t;
                lo1=mid1;
            }else
                hi1=mid1;
        }
        return ret+ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, double p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << p2;
	cout << "]" << endl;
	MixingLiquids *obj;
	double answer;
	obj = new MixingLiquids();
	clock_t startTime = clock();
	answer = obj->howMuch(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
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
	vector <int> p1;
	int p2;
	double p3;

	{
	// ----- test 0 -----
	int t0[] = {0,100};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {20,30};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 50;
	p3 = 40.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {0,100};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {20,30};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 60;
	p3 = 50.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	int t0[] = {90,70,80};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10,10,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 50;
	p3 = 0.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {30,80,60};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {40,10,15};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 57;
	p3 = 35.18518518518519;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	int t0[] = {50,50,50};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {395,971,964};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 50;
	p3 = 2330.0;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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