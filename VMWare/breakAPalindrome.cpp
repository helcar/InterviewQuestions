#include <vector>
#include <iostream>
#include <string>

using namespace std;

string breakAPalindrome(string str) {
    string res = "";
    int idx = -1;
    bool found = false;
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != 'a') {
            idx = i;
            found = true;
            break;
        }
    }
    if (found) {
        for (int i = 0; i < str.size(); i++) {
            if (i != idx) res += str[i];
            else res += "a";
        }
        return res;
    } else 
        return "IMPOSSIBLE";
}

int main() {
    string str = "aba";
    string res = breakAPalindrome(str);
    cout << res << endl;
    return 0;
}