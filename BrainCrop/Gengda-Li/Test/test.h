#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

/**
 * 
 * @param  {int} size               : 
 * @param  {int} range              : 
 * @return {vector<vector<float>>}  : 
 */
vector<vector<float>> gen_random_test(int col, int row, int range) {
    if (col < 0 || row > 1000 || row < 0) {
        cout << "input out of size" << endl;
        exit(1);
    }
    cout << "Random test case: " << endl;
    cout << " We will generate a " << col << " * " << row << " input size matrix" << endl;
    vector<vector<float>> res(col, vector<float>(row));
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            res[i][j] = rand() % range;
        }
    }
    return res;
}

/**
 * 
 * @param  {vector<vector<float>>} T1 : 
 * @param  {vector<vector<float>>} T2 : 
 */
void check(vector<vector<float>>& T1, vector<vector<float>>& T2) {
    int T1_size = T1.size();
    int T2_size = T2.size();
    if (T1_size != T2_size) {
        cout << "test failed" << endl;
        return ;
    }
    for (int i = 0; i < T1.size(); i++) {
        if (T1[i] == T2[i]) cout << "T" << i << " check: Passed" << endl; 
        else cout << "T" << i << " check: Failed" << endl; 
    }
    cout << " " << endl;
}


void showInformation() {

	cout << "Title: Robotic Engineer - Entry/Mid Level" << endl;
	cout << "Name: Gengda Li" << endl;
	cout << "Date: 2020.02.26" << endl;
	cout << "Language: C++" << endl;
	cout << "Environment: VSCode" << endl;
	cout << "GitHub Pages: https://github.com/SaberDa/InterviewQuestions/tree/master/BrainCrop" << endl;
	cout << " " << endl;

}

void print(vector<vector<float>>& nums) {
    for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums[0].size(); j++) {
			cout << nums[i][j] << "\t";
		}
		cout << " " << endl;
	}
	cout << " " << endl;
}

void statement() {

    showInformation();

}