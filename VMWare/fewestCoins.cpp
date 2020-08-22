#include <vector>
#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        int left = 0;
        int right = 0;
        int count = 0;
        int minlen = INT_MAX;
        string res = "";
        for (auto x : t) {
            m[x]++;
            count++;
        }
        while (right < s.size()) {

            
            if (m[s[right]] > 0) {
                count--;
            }
            m[s[right]]--;
            right++;
            
            if (count == 0) {
                while (m[s[left]] < 0) {
                    m[s[left]]++;
                    left++;
                }
                int len = right - left;
                if (len < minlen) {
                    minlen = len;
                    res = s.substr(left, len);
                }
                m[s[left]]++;
                left++;
                count++;
            }
        }
        return res;
    }