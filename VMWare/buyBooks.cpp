#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int buyBooks(vector<int> &book, vector<int> &costs, int budget) {
    int size = book.size();
    vector<vector<int>> dp(size + 1, vector<int>(budget + 1, 0));
    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < budget + 1; j++) {
            if (costs[i - 1] > budget) dp[i][j] = dp[i - 1][j];
            else {
                int nthCost = costs[i - 1];
                int noSelectSum = dp[i - 1][j];
                int selectVal = book[i - 1];
                int selectSum = dp[i - 1][j - nthCost] + selectVal;
                dp[i][j] = max(noSelectSum, selectSum);
            }
        }
    }
    return dp.back().back();
}

int main() {
    vector<int> book({60, 100, 120});
    vector<int> costs({10, 20, 30});
    int budget = 50;
    int res = buyBooks(book, costs, budget);
    cout << res << endl;
    return 0;
}