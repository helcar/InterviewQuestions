#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void helper(string s, string path, vector<string>& res) {
    if (s.empty()) {
        if (find(res.begin(), res.end(), path) == res.end()) {
            res.push_back(path);
        }
        return;
    }
    helper(s.substr(1), path + s[0], res);
    helper(s.substr(1), path, res);
}

vector<string> buildSequence(string s) {
    vector<string> res;
    helper(s, "", res);
    return res;
}

int main() {
    string s = "xyz";
    vector<string> res = buildSequence(s);
    for (auto it : res) cout << it << endl;
    return 0;
}