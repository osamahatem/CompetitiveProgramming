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


class InputBoxChecker {
public:
	vector <string> checkPrefix(int smallest, int largest, vector <int> numbers) {
		vector<string> ret;
		bool flag;
		int s,l;
        for(int i=0;i<numbers.size();i++){
            s=smallest,l=largest;
            flag=0;
            while(s>0 || l>0){
                if(numbers[i]<=l && numbers[i]>=s)
                    flag=1;
                s/=10;
                l/=10;
            }
            if(flag)
                ret.push_back("VALID");
            else
                ret.push_back("INVALID");
        }
        return ret;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, bool hasAnswer, vector <string> p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	InputBoxChecker *obj;
	vector <string> answer;
	obj = new InputBoxChecker();
	clock_t startTime = clock();
	answer = obj->checkPrefix(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p3.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p3[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p3.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p3[i]) {
					res = false;
				}
			}
		}
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
	vector <int> p2;
	vector <string> p3;

	{
	// ----- test 0 -----
	p0 = 300;
	p1 = 347;
	int t2[] = {37};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"INVALID"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 310;
	p1 = 320;
	int t2[] = {3,31,317,3174,310,320};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"VALID","VALID","VALID","INVALID","VALID","VALID"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 600;
	p1 = 1020;
	int t2[] = {7,73,734,7349};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"VALID","VALID","VALID","INVALID"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 64;
	p1 = 78;
	int t2[] = {1,2,3,4,5,6,7,8,9};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"INVALID","INVALID","INVALID","INVALID","INVALID","VALID","VALID","INVALID","INVALID"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 1;
	p1 = 1234567890;
	int t2[] = {123,456,789,1234567,7654321,3245354,325432532,243212};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"VALID","VALID","VALID","VALID","VALID","VALID","VALID","VALID"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
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