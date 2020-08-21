#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    if (strs.empty()) return res;
    unordered_map<string, vector<string>> mp;
    for (auto s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }
    for (auto it : mp) {
        res.push_back(it.second);
    }
    return res;
}