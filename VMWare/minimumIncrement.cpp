#include <iostream>
#include <vector>

using namespace std;

int getMinSum(vector<int> &nums) {
    if (nums.empty()) return 0;
    int sum = nums[0], prev = sum;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] <= prev) {
            prev++;
            sum += prev;
        } else {
            sum += nums[i];
            prev = nums[i];
        }
    }
    return sum;
}