#include <bits/stdc++.h>
using namespace std;



#define ll long long


bool canPartition(vector<int>& nums) {
    ll sum = 0;
    unsigned int n = nums.size();
    for (ll i = 0; i < n; i++) sum += nums[i];

    // can't divide odd number with 1
    if (sum % 2 == 1) return false;

    bool dp[n + 1][sum / 2 + 1];

    dp[0][0] = true;
    for (ll i = 1; i < n + 1; i++) {
        dp[i][0] = false;
    }
    for (ll j = 1; j < sum / 2 + 1; j++) {
        dp[0][j] = false;
    }

    for (ll i = 1; i < n + 1; i++) {
        for (ll j = 1; j < sum / 2 + 1; j++) {
            if (j < nums[i - 1]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
        }
    }

    return dp[n][sum / 2];
}



// to test
int main() {
    ios::sync_with_stdio(false);


    // test1
    vector<int> toTest1 = {1, 5, 11, 5};
    if (canPartition(toTest1)) cout << "Correct!" << endl;
    else cout << "Wrong!" << endl;

    //test2
    vector<int> toTest2 = {1, 2, 3, 5};
    if (!canPartition(toTest2)) cout << "Correct!" << endl;
    else cout << "Wrong!" << endl;




    return 0;
}
