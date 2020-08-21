#include <vector>
#include <iostream>

using namespace std;

int helper(char c) {
    if (c == 'H') return 5;
    else if (c == 'M') return 3;
    else return 1;
}

string countScore(string str1, string str2) {
    int diff = 0;
    for (int i = 0; i < str1.size(); i++) {
        diff += helper(str1[i]) - helper(str2[i]);
    }
    if (diff > 0) return str1;
    else if (diff == 0) return "TIE";
    else return str2;
}