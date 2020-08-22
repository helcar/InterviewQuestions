#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int helper(vector<int> &input, bool reverse) {
    vector<int> temp = input;
    sort(temp.begin(), temp.end());
    if (reverse) {
        for (int i = 0, j = temp.size() - 1; i < j; i++, j--) {
            int tmp = temp[i];
            temp[i] = temp[j];
            temp[j] = tmp;
        }
    }
    vector<vector<int>> dp(input.size(), vector<int>(temp.size()));
    dp[0][0] = abs(input[0] - temp[0]);
    for (int i = 1; i < input.size(); i++) {
        dp[i][0] = dp[i - 1][0] + abs(input[i] - temp[0]);
    }
    for (int j = 1; j < temp.size(); j++) {
        dp[0][j] = min(dp[0][j - 1], abs(input[0] - temp[j]));
    }
    for (int i = 1; i < input.size(); i++) {
        for (int j = 1; j < temp.size(); j++) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j] + abs(input[i] - temp[j]));
        }
    }
    return dp.back().back();
}

int getMinimumCost(vector<int>& input) {
    if (input.empty()) return 0;
    return min(helper(input, false), helper(input, true));
}

int main() {
    vector<int> input({0, 1, 2, 5, 6, 5, 7});
    int res = getMinimumCost(input);
    cout << res << endl;
    return 0;
}

