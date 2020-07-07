////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: Overexcited Fan.cpp
//	Problem Source: GCJ - Round 1C
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 04/05/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//  At every step of the tour, check if the Manhattan distance to that point is
//  small enough to reach that position in time, and take the earliest such
//  position.
//
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

int mdx[128], mdy[128];

int main() {
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    mdx['N'] = mdx['S'] = mdy['E'] = mdy['W'] = 0;
    mdx['E'] = mdy['N'] = 1;
    mdx['W'] = mdy['S'] = -1;

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int X, Y;
        string moves;
        cin >> X >> Y >> moves;

        int ans = -1, x = X, y = Y, pos = 0;
        do {
            if (abs(x) + abs(y) <= pos) {
                ans = pos;
                break;
            }
            x += mdx[moves[pos]], y += mdy[moves[pos]];
            pos++;
        } while (pos <= moves.size());

        cout << "Case #" << t << ": ";
        if (ans == -1)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
