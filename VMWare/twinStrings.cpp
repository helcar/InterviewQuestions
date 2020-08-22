#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool twinStrings(string str1, string str2) {
    if (str1.size() != str2.size()) return false;
    unordered_map<char, int> odd, even;
    for (int i = 0; i < str1.size(); i++) {
        if (i % 2 == 0) {
            even[str1[i]]++;
            even[str2[i]]--;
        } else {
            odd[str1[i]]++;
            odd[str2[i]]--;
        }
    }
    for (auto it : odd) {
        if (it.second != 0) return false;
    }
    for (auto it : even) {
        if (it.second != 0) return false;
    }
    return true;
}

int main() {
    string str1 = "abcde";
    string str2 = "edabc";
    bool res = twinStrings(str1, str2);
    cout << res << endl;
    return 0;
}