#include <bits/stdc++.h>
using namespace std;


//#define ll long long



int maxSumDivThree(vector<int>& nums) {
    unsigned int n = nums.size();

    // each element is 3-element vector filled with modulo 3
    vector<int> dp[n + 1];
    for (int i = 1; i < n + 1; i++) dp[i] = {-1, -1, -1};
    dp[1][0] = (nums[0] % 3 == 0)? nums[0] : 0;
    dp[1][1] = (nums[0] % 3 == 1)? nums[0] : 0;
    dp[1][2] = (nums[0] % 3 == 2)? nums[0] : 0;

    for (int i = 2; i < n + 1; i++) {
        switch (nums[i - 1] % 3) {
            case 0:
                dp[i][0] = dp[i - 1][0] + nums[i - 1];
                dp[i][1] = (dp[i - 1][1] != 0)? dp[i - 1][1] + nums[i - 1] : 0;
                dp[i][2] = (dp[i - 1][2] != 0)? dp[i - 1][2] + nums[i - 1] : 0;
                break;
            case 1:
                dp[i][0] = (dp[i - 1][2] != 0)?
                                max(dp[i - 1][0], dp[i - 1][2] + nums[i - 1]) : dp[i - 1][0];
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i - 1]);
                dp[i][2] = (dp[i - 1][1] != 0)?
                                max(dp[i - 1][2], dp[i - 1][1] + nums[i - 1]) : dp[i - 1][2];
                break;
            case 2:
                dp[i][0] = (dp[i - 1][1] != 0)?
                                max(dp[i - 1][0], dp[i - 1][1] + nums[i - 1]) : dp[i - 1][0];
                dp[i][1] = (dp[i - 1][2] != 0)?
                                max(dp[i - 1][1], dp[i - 1][2] + nums[i - 1]) : dp[i - 1][1];
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + nums[i - 1]);
                break;
        }
    }

    return dp[n][0];
}


int main171() {
    ios::sync_with_stdio(false);

    // test1
    vector<int> vec1 = {3, 6, 5, 1, 8};
    if (maxSumDivThree(vec1) == 18) cout << "Correct!" << endl;
    else cout << "Wrong!" << endl;

    // test2
    vector<int> vec2 = {4};
    if (maxSumDivThree(vec2) == 0) cout << "Correct!" << endl;
    else cout << "Wrong!" << endl;

    // test3
    vector<int> vec3 = {1, 2, 3, 4, 4};
    if (maxSumDivThree(vec3) == 12) cout << "Correct!" << endl;
    else cout << "Wrong!" << endl;




    return 0;
}