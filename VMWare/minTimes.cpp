#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int minTimes(vector<float> &items) {
    sort(items.begin(), items.end());
    int i = 0, cnt = 0;
    while (i < items.size()) {
        int j = i, total = 0;
        while (j < items.size() && total + items[j] <= 3) {
            total += items[i];
            j++;
        }
        cnt++;
        i = j;
    }
    return cnt;
}

int main() {
    vector<float> items({1.01, 1.01, 1.99, 2.5});
    int res = minTimes(items);
    cout << res << endl;
    return res;
}