////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: 1332E. Height All the Same.cpp
//	Problem Source: Codeforces Round #630 (Div. 2)
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 01/04/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	https://codeforces.com/blog/entry/75432
//
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353ll

long long fast_power(long long b, long long p) {
    long long ret = 1;
    for (; p; p >>= 1) {
        if (p & 1)
            ret = ret * b % MOD;
        b = b * b % MOD;
    }
    return ret;
}

int main() {
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    long long n, m, l, r;
    cin >> n >> m >> l >> r;

    n *= m;
    long long range = r - l + 1;

    long long ans = fast_power(range, n);
    if ((n & 1) == 0)
        ans = (ans + (range & 1)) * fast_power(2, MOD - 2) % MOD;

    cout << ans << "\n";

    return 0;
}

