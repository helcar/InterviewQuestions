#include <iostream>
#include <vector>

using namespace std;

int evenSubarray(vector<int>& numbers, int k) {
    int left = 0, count = 0, res = 0;

    for (int i = 0; i < numbers.size(); i++) {
        int right = i;
        int num = numbers[i];
        if (num % 2) count++;
        if (count > k) {
            while (numbers[left] % 2 == 0) left++;
            left++;
            count--;
        }
        res += (right - left + 1);
    }

    return res;
}

int main() {
    vector<int> nums({1, 2, 3, 4});
    int k = 3;
    int res = evenSubarray(nums, k);
    cout << res << endl;
    return 0;
}