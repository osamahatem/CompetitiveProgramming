////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: 1332A. Exercising Walk.cpp
//	Problem Source: Codeforces Round #630 (Div. 2)
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 31/03/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//  Notice that the 2 axis are independent, so we can check every direction on
//  on its own. We can always alternate movement between up/down or left/right
//  in order not to stray too far from origin, until we're left with only one
//  option, which means we need to only compare the limits of our grid with the
//  max leftover steps in a given direction. Special care for the case where the
//  leftover is 0, and the limits are exact.
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

    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d, x, y, x1, y1, x2, y2;
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        int xdiff = x - a + b, ydiff = y - c + d;
        if (xdiff >= x1 && xdiff <= x2 && ydiff >= y1 && ydiff <= y2 && x2 - x1 >= (xdiff == x && (a || b)) && y2 - y1 >= (ydiff == y && (c || d)))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}

