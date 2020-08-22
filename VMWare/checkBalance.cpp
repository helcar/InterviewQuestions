#include <vector>
#include <iostream>

using namespace std;

bool checkBalance (string exp, int k) {
    int needed = 0, left = 0, right = 0;
    for (auto c : exp) {
        if (c == '<') left++;
        else {
            if (left <= 0) needed++;
            else left--;
        }
    }
    return left == 0 && needed <= k;
}

int main() {
    string exp = "<>>";
    int k = 1;
    bool res = checkBalance(exp, k);
    cout << res << endl;
    return 0;
}