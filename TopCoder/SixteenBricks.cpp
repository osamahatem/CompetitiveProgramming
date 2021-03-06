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

int arr[4][4],dx[]={-1,0,1,0},dy[]={0,-1,0,1};

int trim(int r,int c){
    int ret=0;
    for(int i=0;i<4;i++){
        int x=r+dx[i];
        int y=c+dy[i];
        if(x<0 || y<0 || x==4 || y==4)
            continue;
        ret+=min(arr[x][y],arr[r][c]);
    }
    return ret;
}

class SixteenBricks {
public:
	int maximumSurface(vector <int> height) {
		int ans=16;
		for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                arr[i][j]=0;
        sort(height.begin(),height.end());
        arr[0][0]=height[height.size()-1];
        ans+=4*arr[0][0];
        height.pop_back();
        arr[0][3]=height[height.size()-1];
        ans+=4*arr[0][3];
        height.pop_back();
        arr[3][0]=height[height.size()-1];
        ans+=4*arr[3][0];
        height.pop_back();
        arr[3][3]=height[height.size()-1];
        ans+=4*arr[3][3];
        height.pop_back();
        int cur=0;
        for(int i=1;i<3;i++){
            for(int j=1;j<3;j++){
                arr[i][j]=height[cur++];
                ans+=4*arr[i][j]-2*trim(i,j);
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(arr[i][j])
                    continue;
                arr[i][j]=height[cur++];
                ans+=4*arr[i][j]-2*trim(i,j);
            }
        }
        return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	SixteenBricks *obj;
	int answer;
	obj = new SixteenBricks();
	clock_t startTime = clock();
	answer = obj->maximumSurface(p0);
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

	vector <int> p0;
	int p1;

	{
	// ----- test 0 -----
	int t0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 32;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 64;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	int t0[] = {77,78,58,34,30,20,8,71,37,74,21,45,39,16,4,59};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1798;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
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
