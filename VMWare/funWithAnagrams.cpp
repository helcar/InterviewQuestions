#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<string> funWithAnagrams(vector<string> &str) {
    vector<string> res;
    if (str.empty()) return res;
    unordered_set<string> st;
    for (auto s : str) {
        string key = s;
        sort(key.begin(), key.end());
        if (st.count(key)) continue;
        st.insert(key);
        res.push_back(s);
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    vector<string> str({"code", "doce", "ecod", "framer", "frame"});
    vector<string> res = funWithAnagrams(str);
    for (auto s : res) cout << s << " ";
    return 0;
}