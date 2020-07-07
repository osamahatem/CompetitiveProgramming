////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: 1330D. Dreamoon Likes Sequences.cpp
//	Problem Source: Codeforces Round #631 (Div. 2)
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 03/04/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	The main observation here is that the only way to satisfy the required
//  constraints is for each number to have a most-significant bit higher than
//  the one before. Given that, the array length cannot exceed log2(10^9), and
//  the number of possible arrays can be calculated using simple iterative DP.
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
        int d, m;
        cin >> d >> m;
        int msb = 0;
        while ((1 << msb) <= d)
            msb++;
        msb--;

        long long ans = 0;
        for (int i = 0; i <= msb; i++)
            ans = (ans + (i == msb ? d - (1ll << i) + 1 : (1ll << i)) * (ans + 1)) % m;
        cout << ans << endl;
    }

    return 0;
}

