#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int climbHill(vector<int> &a) {
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int> b = a;
    sort(b.begin(), b.end());
    dp[1][1] = abs(a[0] - b[0]);
    for (int j = 1; j < n + 1; j++) {
        if (j > 1) dp[1][j] = min(dp[1][j - 1], abs(a[0] - b[j - 1]));
    }
    for (int i = 1; i < n + 1; i++) {
        if (i > 1) dp[i][1] = dp[i - 1][1] + abs(a[i - 1] - b[0]);
    }
    for (int i = 2; i < n + 1; i++) {
        for (int j = 2; j < n + 1; j++) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j] + abs(a[i - 1] - b[j - 1]));
        }
    }
    return dp[n][n];
}

int main() {
    vector<int> a({0, 1, 2, 5, 5, 4, 4});
    int res = climbHill(a);
    cout << res << endl;
    return 0;
}