#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isNormal(char ch, string charValue) {
    return charValue[ch - 'a'] == '0';
}

int getSpecialSubstring(string s, int k, string charValue) {
    int res = -1;
    // int i = 0, j = 0, cnt = 0;
    // while (j < s.size()) {
    //     if (isNormal(s[j], charValue)) cnt++;
    //     j++;
    //     while (i < j && cnt > k) {
    //         if (isNormal(s[i], charValue)) cnt--;
    //         i++;
    //     }
    //     if (cnt <= k) res = max(j - i, res);
    // }
    int left = 0, count = 0;
    for (int i = 0; i < s.size(); i++) {
        count += isNormal(s[i], charValue);
        if (count > k) {
            while (isNormal(s[left], charValue) == 0) left++;
            left++;
            count--;
        }
        int temp = i - left + 1;
        res = max(res, temp);
    }
    return res;
}

int main() {
    string s = "abcde";
    int k = 2;
    string charValue = "10101111111111111111111111";
    int res = getSpecialSubstring(s, k, charValue);
    cout << res << endl;
    return 0;
}