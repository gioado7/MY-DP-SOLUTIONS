#include <bits/stdc++.h>
using namespace std;



//#define ll long long




int m100ain() {
    ios::sync_with_stdio(false);


    int n;
    cin >> n;

    vector<double> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    double dp[n + 1][n + 1];




    // to fix
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == 1) dp[i][j] = p[i];
            else dp[i][j] = dp[i][j - 1] * p[i];
        }

    }

    return 0;
}