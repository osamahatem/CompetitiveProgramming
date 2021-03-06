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

struct node {
	int sr, sc, er, ec;
};

int maxFoldRow[55], maxFoldCol[55];
bool vis[55][55][55][55];

int solve(int sr, int sc, int er, int ec) {
	int ans = 0;
	queue<node> Q;
	Q.push(node { sr, sc, er, ec });
	while (Q.size()) {
		node cur = Q.front();
		Q.pop();
		sr = cur.sr, sc = cur.sc, er = cur.er, ec = cur.ec;
		if (vis[sr][sc][er][ec])
			continue;
		ans++;
		vis[sr][sc][er][ec] = 1;

		for (int i = sr; i < er; i++) {
			int len = min(i - sr + 1, er - i);
			if (maxFoldRow[i] < len)
				continue;
			if (len == i - sr + 1 && !vis[i + 1][sc][er][ec])
				Q.push(node { i + 1, sc, er, ec });
			if (len == er - i && !vis[sr][sc][i][ec])
				Q.push(node { sr, sc, i, ec });
		}

		for (int i = sc; i < ec; i++) {
			int len = min(i - sc + 1, ec - i);
			if (maxFoldCol[i] < len)
				continue;
			if (len == i - sc + 1 && !vis[sr][i + 1][er][ec])
				Q.push(node { sr, i + 1, er, ec });
			if (len == ec - i && !vis[sr][sc][er][i])
				Q.push(node { sr, sc, er, i });
		}
	}
	return ans;
}

class BoardFoldingDiv2 {
public:
	int howMany(vector<string> paper) {
		fill(maxFoldRow, maxFoldRow + 55, 55);
		fill(maxFoldCol, maxFoldCol + 55, 55);
		memset(vis, 0, sizeof vis);
		int n = paper.size(), m = paper[0].size();

		for (int i = 0; i + 1 < n; i++) {
			for (int j = 0; j < m; j++) {
				int temp = 0, idx = 0;
				while (i - idx >= 0 && i + 1 + idx < n
						&& paper[i - idx][j] == paper[i + 1 + idx][j]) {
					temp++;
					idx++;
				}
				maxFoldRow[i] = min(maxFoldRow[i], temp);
			}
		}

		for (int i = 0; i + 1 < m; i++) {
			for (int j = 0; j < n; j++) {
				int temp = 0, idx = 0;
				while (i - idx >= 0 && i + 1 + idx < m
						&& paper[j][i - idx] == paper[j][i + 1 + idx]) {
					temp++;
					idx++;
				}
				maxFoldCol[i] = min(maxFoldCol[i], temp);
			}
		}

		return solve(0, 0, n - 1, m - 1);
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector<string> p0, bool hasAnswer,
		int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	BoardFoldingDiv2 *obj;
	int answer;
	obj = new BoardFoldingDiv2();
	clock_t startTime = clock();
	answer = obj->howMany(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC
			<< " seconds" << endl;
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

	vector<string> p0;
	int p1;

	{
		// ----- test 0 -----
		string t0[] = { "10", "11" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 1;
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		string t0[] = { "1111111", "1111111" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 84;
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		string t0[] = { "0110", "1001", "1001", "0110" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 9;
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		string t0[] = { "0", "0", "0", "1", "0", "0" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 6;
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		string t0[] = { "000", "010", "000" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 1;
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
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
