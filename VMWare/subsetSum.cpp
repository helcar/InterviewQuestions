#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;


vector<int> subsetA(vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    
    // generate the knapsack items and find the max weight
    struct Item {
        int value, weight, actual;
    };
    vector<Item> items;
    int last = 0, max_weight = 0;
    for (int item : arr) {
        max_weight += item;
        if (items.size() == 0 || item != last) {
            items.push_back(Item{1, item, item});
        } else {
            items[items.size() - 1].value++;
            items[items.size() - 1].weight += item;
        }
        last = item;
    }
    max_weight = (max_weight - 1)/2;
    
    // iterative 0/1 knapsack
    vector<vector<int>> dp(items.size(), vector<int>(max_weight + 1, 0));
    for (int i = 0; i < items.size(); i++) {
        for (int weight = 0; weight <= max_weight; weight++) {
            int skip = (i == 0) ? 0 : dp[i - 1][weight];
            int include = 0;
            if (items[i].weight <= weight) {
                include = items[i].value;
                if (i > 0) include += dp[i - 1][weight - items[i].weight];
            }
            dp[i][weight] = std::max(include, skip);
        }
    }
    
    // retrieve the items that were included in B
    unordered_set<int> B;
    int weight = max_weight;
    for (int i = items.size() - 1; i > 0; i--) {
        if (dp[i - 1][weight] != dp[i][weight]) {
            B.insert(items[i].actual);
            weight -= items[i].weight;
        }
    }
    if (weight > 0) B.insert(items[0].actual);

    // now invert B to get A
    vector<int> A;
    for (int num : arr) {
        if (B.find(num) == B.end()) A.push_back(num);
    }
    
    return A;
}
