#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool subsequenceRemoval(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (auto c : nums) {
        mp[c]++;
    }
    vector<int> temp;
    for (auto it : mp) {
        if (it.second > 1) temp.push_back(it.first);
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < nums.size();) {
        if (nums[i] == temp[0]) {
            for (int j = 0; j < temp.size() && i < nums.size(); j++) {
                if (nums[i] != temp[j]) return false;
                i++;
            }
        }
        i++;
    }
    for (auto c : temp) cout << c << " ";
    cout << endl;
    return true;
}

int main() {
    vector<int> nums({1, 2, 3, 2, 3, 4, 1});
    bool res = subsequenceRemoval(nums);
    cout << res << endl;
    return 0;
}