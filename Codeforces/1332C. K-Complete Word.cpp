////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: 1332C. K-Complete Word.cpp
//	Problem Source: Codeforces Round #630 (Div. 2)
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 31/03/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Given the constraints in the problem statement, we can partition the
//  positions in the string so that those that must be equal are together.
//  Then, for each partition, check which letter occurs the most and change the
//  rest to match it.
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
        int n, k;
        string s;
        cin >> n >> k >> s;
        int ans = 0;

        for (int i = 0; i < (k + 1)/ 2; i++) {
            int total = 2 * n / k;
            int cnt[26] = { 0 };
            for (int idx = 0; idx < n; idx += k)
                cnt[s[idx + i] - 'a']++, cnt[s[idx + k - i - 1] - 'a']++;

            int maxi = 0;
            for (int c = 0; c < 26; c++)
                maxi = max(maxi, cnt[c]);
            ans += (total - maxi) / ((k & 1) && (i == k / 2) ? 2 : 1);
        }

        cout << ans << "\n";
    }

    return 0;
}
