////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: 1332D. Walk on Matrix.cpp
//	Problem Source: Codeforces Round #630 (Div. 2)
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 31/03/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Construction problem. Second sample is basically the solution. Construct two
//  paths such that the value of both of them share no 1-bits (a & b = 0). These
//  two paths will only meet in the last cell, which is set-up to favour the
//  lower, but correct path, while the described algorithm will pick the higher
//  value early.
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

    int k;
    cin >> k;

    int ans[3][4] = { 0 };
    if (k) {
        int n = 0;
        while ((1 << n) <= k)
            n++;
        n--;
        ans[0][0] = ans[0][1] = ans[0][2] = ans[1][0] = ans[2][1] = ans[2][2] = (1 << (n + 2)) - 1;
        ans[1][2] = k;
        ans[2][0] = 1 << (n + 1);
        ans[2][3] = (1 << (n + 1)) - 1;
    }

    cout << "3 4\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            cout << ans[i][j] << " \n"[j == 3];
    }

    return 0;
}

