////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: ESAb ATAd.cpp
//	Problem Source: GCJ 2020 - Qualification Round
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 04/04/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e
//
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

int arr[105];

int main() {
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);

    // cin.tie(0);
    // cout.tie(0);
    // ios::sync_with_stdio(false);

    int T, B;
    cin >> T >> B;

    while (T--) {
        int odd = 0, even = 0, q = 0, pair_cnt = 0;
        while (pair_cnt < B / 2) {
            q = q + 1;
            if (q > 10)
                q -= 10;

            int pos = 1, ans;
            if (q == 1 && odd)
                pos = odd;
            else if (q == 2 && even)
                pos = even;
            else if (q > 2 && (q & 1))
                pos = pair_cnt + 1;
            else if (q > 2)
                pos = B - pair_cnt;

            cout << pos << endl;
            string ret;
            cin >> ret;
            assert(ret != "N");
            ans = ret[0] - '0';

            if (q == 1 && odd && ans != arr[odd]) {
                for (int i = 1; i <= pair_cnt; i++)
                    if (arr[i] != arr[B - i + 1])
                        arr[i] = 1 - arr[i], arr[B - i + 1] = 1 - arr[B - i + 1];
            } else if (q == 2 && even && ans != arr[even]) {
                for (int i = 1; i <= pair_cnt; i++)
                    if (arr[i] == arr[B - i + 1])
                        arr[i] = 1 - arr[i], arr[B - i + 1] = 1 - arr[B - i + 1];
            } else if (q > 2 && (q & 1)) {
                arr[pos] = ans;
            } else if (q > 2) {
                arr[pos] = ans;
                if (arr[pos] == arr[B - pos + 1] && !even)
                    even = B - pos + 1;
                else if (arr[pos] != arr[B - pos + 1] && !odd)
                    odd = B - pos + 1;
                pair_cnt++;
            }
        }

        string ans = "";
        for (int i = 1; i <= B; i++)
            ans += '0' + arr[i];
        cout << ans << endl;

        string ret;
        cin >> ret;
        assert(ret == "Y");
    }

    return 0;
}

