////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: Foregone Solution.cpp
//	Problem Source: GCJ 2019 - Qualification Round
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 06-04-2019
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Solution summary goes here.
//
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string num;
        cin >> num;

        string a = "", b = "";
        int carry = 0;
        for (int i = num.length() - 1; i >= 0; i--) {
            int digit = num[i] - '0' - carry;
            if (digit <= 0) {
                if (i == 0) {
                    break;
                }

                digit += 10;
                carry = 1;
            } else {
                carry = 0;
            }

            a += '1', b += '0' + digit - 1;
            if (b.back() == '4') {
                a.back()++, b.back()--;
            }

            if (i == num.length() - 1 && digit == 1) {
                a[0] = '5', b[0] = '6';
                carry = 1;
            }
        }

        while (a.back() == '0') {
            a.pop_back();
        }
        while (b.back() == '0') {
            b.pop_back();
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        cout << "Case #" << t << ": " << a << " " << b << endl;
    }

    return 0;
}
