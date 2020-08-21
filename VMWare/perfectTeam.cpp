#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int differentTeams(string skills) {
    unordered_map<char, int> mp;
    for (auto c : skills) {
        mp[c]++;
    }
    if (mp.size() < 5) return 0;
    int maxNum = INT_MAX;
    for (auto it : mp) {
        if (it.second < maxNum) {
            maxNum = it.second;
        }
    }
    return maxNum == INT_MAX ? 0 : maxNum;
}