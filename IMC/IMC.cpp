#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

size_t getNum(string str) {
    string temp = str.substr(0, str.size() - 1);
    return stoll(temp);
}

char getChar(string str) {
    return str.back();
}

vector<int> solution(int N, string &artifacts, string &searched) {
    // write your code in C++
    
    vector<int> res(2, 0);
    int count = 0, total = 0;
    
    if (artifacts.empty() || searched.empty() || (N <= 0 || N > 26)) return res;
    
    vector<string> arts, each;
    stringstream s1(artifacts);
    string s;
    while (getline(s1, s, ',')) arts.push_back(s);
    s = "";
    
    // for (auto s : arts) cout << s << endl;
    
    unordered_map<string, int> mp;
    stringstream s2(searched);
    while (getline(s2, s, ' ')) mp[s]++;
    s = "";
    
    // for (auto it : mp) cout << it.first << " " << it.second << endl;
    
    for (int i = 0; i < (int)arts.size(); i++) {
        count = 0, total = 0;
        
        stringstream s3(arts[i]);
        while (getline(s3, s, ' ')) each.push_back(s);
        s = "";
        
        // cout << "each" << endl;
        // for (auto s : each) cout << s << endl;
        
        size_t jStart, jEnd;
        char kStart, kEnd;
        
        jStart = getNum(each[0]);
        jEnd = getNum(each[1]);
        kStart = getChar(each[0]);
        kEnd = getChar(each[1]);
        
        for (size_t j = jStart; j <= jEnd; j++) {
            for (char k = kStart; k <= kEnd; k++) {
                total++;
                // cout << "j: " << j << "k: " << k << endl;
                string temp = to_string(j) + k;
                // cout << "temp:" << temp << endl;
                if (mp.count(temp)) count++;
            }
        }
        
        if (total > 4) {
            cout << "ERROR" << endl;
            return vector<int>();
        }
        
        if (total == count) res[0]++;
        else {
            if (count != 0) res[1]++;
        }
        
        each.clear();
    }
    
    return res;
}

int main() {
    vector<int> temp;
    string art, search;
    int N = 0;

    // N = 4;
    // art = "1B 2C,2D 4D";
    // search = "2B 2D 3D 4D 4A";

    N = 3;
    art = "1A 1B,2C 2C";
    search = "1B";

    temp = solution(N, art, search);

    for (auto c : temp) cout << c << endl;
    return 0;
}