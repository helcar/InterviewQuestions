/*
 * Other's Phone Screen, Azure 
 * 
 * I don't find the origin problem in LeetCode,
 * so write it in this folder.
*/

/* His Interview Experience

This phone screen was for 1 hr.

    - Interviewer Introduction (2 minutes)
    - Myself (2 minutes)
    - Role and Team description (2 minutes)

The interviewer asked me to share my entire desktop on Teams and code it on my browser or local.

You are given a number and a digit and the aim is to place the digit anywhere within the number to obtain the maximum. For ex:
    Input: (num=672, d=5) Output: 6752
    Input: (num=284, d=3) Output: 3284
    Explained him the approach on whiteboard where we will generate all possible cases and keep track of the max.
    For Ex: (num=672, d=5)

All possible generated numbers are:
    5672,6572,6752,6725. Out of these all 6752 is the biggest.

    - Coded and explained him (30 minutes)

    - Asked me to think about cases where it can break. Told him about negative numbers and out of range capacity (5 minutes)
    - Asked me to optimize the solution (but didn't want me to code). I told him an we can find a local minima point starting from left and place the digit before the local minima. (5 minutes)
    - Explained about microsoft and any other questions (5 minutes)
*/

/*
 * My solution:
 * 1. Save the digits into a vector
 * 2. Loop from the Most Significant Digit to reconstruct the number, allocating a long long (otherwise a int can overflow)
 * 3. As soon as we find one digit in the number that is smaller than the digit provided as parameter, inject the digit
 * 4. Complete the loop with the rest of digits
 * 
 * Complexity: time and space are O(log(num))
*/

#include <iostream>
#include <vector>

using namespace std;

long long getMax(int num, int digit) {
    vector<int> digits;

    while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }

    long long res = 0;
    int length = digits.size() - 1;

    while (length >= 0 && digits[length] > digit) res = res * 10 + digits[length--];
    res = res * 10 + digit;
    while (length >= 0) res = res * 10 + digits[length--];

    return res;
}

int main() {
    cout << getMax(672, 5) << endl;     // 6752
    cout << getMax(284, 3) << endl;     // 3284
    return 0;
}