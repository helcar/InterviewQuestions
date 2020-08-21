#include <vector>
#include <string>
#include <iostream>

using namespace std;

string getShiftedString(string str, int leftShifts, int rightShifts) {
    if (str == "" || str.empty()) return "";
    if (leftShifts == rightShifts) return str;
    leftShifts = (leftShifts - rightShifts) % str.length();
    return str.substr(leftShifts) + str.substr(0, leftShifts);
}