#include <bits/stdc++.h>
using namespace std;


#define ll long long


int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<ll> dp(n, 0);
    for (int i = 1; i < n; i++) {
        if (i == 1) {
            dp[1] = abs(h[1] - h[0]);
        }else {
            dp[i] = min(dp[i - 2] + abs(h[i] - h[i - 2]),
                          dp[i - 1] + abs(h[i] - h[i - 1]));
        }
    }

    cout << dp[n - 1] << endl;


    return 0;
}
