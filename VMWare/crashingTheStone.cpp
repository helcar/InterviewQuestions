#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int lastStoneWeight(vector<int> &stones) {
    auto comp = [](int &a, int &b){return a < b;};
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    for (auto c : stones) pq.push(c);
    while (pq.size() > 1) {
        int temp = pq.top();
        pq.pop();
        if (temp == pq.top()) pq.pop();
        else {
            int diff = temp - pq.top();
            pq.pop();
            pq.push(diff);
        }
    }
    return pq.size() == 0 ? 0 : pq.top();
}

int main() {
    vector<int> stones({4, 5, 1, 6, 8, 2});
    int res = lastStoneWeight(stones);
    cout << res << endl;
    return 0;
}