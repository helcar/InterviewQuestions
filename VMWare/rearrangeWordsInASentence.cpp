#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

string arrangeWords(string text) {
    map<int, vector<string>> mp;
    stringstream ss(text);
    string temp;
    while (getline(ss, temp, ' ')) {
        mp[temp.size()].push_back(temp);
    }
    string ret = "";
    for (auto m : mp) {
        for(auto s : m.second) {
            ret += (s + " ");
        }
    }
    string re = ret.substr(0, ret.size() - 1);
    transform(re.begin(), re.end(), re.begin(), ::tolower);
    char a = toupper(re[0]);
    string b;
    b.push_back(a);
    b += re.substr(1, re.size() - 1);
    return b;
}