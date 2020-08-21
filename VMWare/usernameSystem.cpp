#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

vector<string> usernamesSystem(vector<string> &inputList) {
    vector<string> res;
    if (inputList.empty()) return res;
    unordered_map<string, int> mp;
    for (auto s : inputList) {
        if (mp.count(s) == 0) {
            mp[s] = 0;
            res.push_back(s);
        }
        else {
            mp[s]++;
            string temp = s + to_string(mp[s]);
            res.push_back(temp);
        }
    }
    return res;
}

int main() {
    vector<string> inputList({"bob", "alice", "bob", "alice", "bob"});
    vector<string> res = usernamesSystem(inputList);

    /*
     * Output: bob alice bob1 alice1 bob2 
    */
    for (auto it : res) cout << it << " ";
    return 0;
}