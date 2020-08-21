#include <iostream>
#include <vector>

using namespace std;

int factorial(int num) {
    if (num == 0) return 1;
    else return num * factorial(num - 1);
}

int countTeams(vector<int> &skills, int k, int l, int r) {
    vector<int> temp;
    for (auto num : skills) {
        if (num <= r && num >= l) temp.push_back(num);
    }
    int n = temp.size();
    int size = k;
    int res = 0;
    while (size <= n) {
        res += factorial(n) / factorial(size) * factorial(n - size);
    }
    return res;
}
