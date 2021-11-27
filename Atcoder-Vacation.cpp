#include <bits/stdc++.h>
using namespace std;


#define ll long long

#define A 0
#define B 1
#define C 2




int main123() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    ll dp[3][n];

    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (i == 0) {
            dp[A][0] = a;
            dp[B][0] = b;
            dp[C][0] = c;
        }else {
            dp[A][i] = max(dp[B][i - 1], dp[C][i - 1]) + a;
            dp[B][i] = max(dp[A][i - 1], dp[C][i - 1]) + b;
            dp[C][i] = max(dp[A][i - 1], dp[B][i - 1]) + c;
        }
    }


    cout << max(max(dp[A][n - 1], dp[B][n - 1]), dp[C][n - 1]) << endl;


    return 0;
}
