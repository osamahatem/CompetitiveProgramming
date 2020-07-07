////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: Nesting Depth.cpp
//	Problem Source: GCJ 2020 - Qualification Round
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 04/04/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f
//
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string s, sa;
        cin >> s;

        int depth = 0;
        for (char dig : s) {
            int d_val = dig - '0';
            while (depth < d_val)
                sa += '(', depth++;
            while (depth > d_val)
                sa += ')', depth--;
            sa += dig;
        }
        while (depth)
            sa += ')', depth--;

        cout << "Case #" << t << ": " << sa << endl;
    }

    return 0;
}

