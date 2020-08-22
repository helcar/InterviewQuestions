#include <vector>
#include <iostream>
#include <queue>

using namespace std;

long getMaxUnit(int num, vector<int> &boxes, int unitSize, vector<int> &unitsPerBox, long truckSize) {
    if (unitSize == 0 || unitsPerBox.empty() || boxes.empty())
    {
        return 0;
    }
    priority_queue<pair<int, int>> pq;
    /* Add inputs to the max heap */
    for (int i = 0; i < unitSize; i++)
    {
        pq.push({unitsPerBox[i], boxes[i]});
    }
    long res = 0;
    while (truckSize > 0 
           && false == pq.empty())
    {
        int curr_unit = pq.top().first;
        int curr_box_ct = pq.top().second;
        pq.pop();
        /* Increment the box count using the unit val * min of truck size or current count*/
        res += curr_unit * min((long)curr_box_ct, truckSize);
        /* Decrement truck size as new boxes are added */
        truckSize -= min((long)curr_box_ct, truckSize);   
    }
    cout << res << endl;
    return res;
    
}

int main() {
	int n1 = 3, ts1 = 3;
	vector<int>b1{1,2,3};
	vector<int>u1{3,2,1};
	int ans1 = getMaxUnit(n1, b1, u1.size(), u1, ts1);
	assert(ans1 == 7);
	int n2 = 3, ts2 = 4;
	int ans2 = getMaxUnit(n2, b1, u1.size(), u1, ts2);
	assert(ans2 == 8);
	return 0;
}