#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

vector<vector<float>> gen_random_test(int size, int range) {
    if (size > 1000 || size < 0) {
        cout << "input out of size" << endl;
        exit(1);
    }
    cout << "Random test case: " << endl;
    cout << " We will generate a " << size << " * " << size << " input size matrix" << endl;
    vector<vector<float>> res(size, vector<float>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = rand() % range;
        }
    }
    return res;
}

// vector<vector<float>>& example() {
//     vector<vector<float>> input;
// 	input.push_back({ 0.,1.,2.,1.,3. });
// 	input.push_back({ 1.,5.,7.,1.,3. });
// 	input.push_back({ 2.,3.,4.,1.,0. });
// 	input.push_back({ 3.,3.,3.,1.,3. });
// 	input.push_back({ 10.,2.,4.,0.,0. });
//     return input;
// }

// vector<vector<float>>& example_med_answer() {
//     vector<vector<float>> med_ans;
//     med_ans.push_back({ 0.,1.,2.,1.,3. });
//     med_ans.push_back({ 0.5,3,4.5,1.,3. });
//     med_ans.push_back({ 1.,3.,4.,1.,3.});
//     med_ans.push_back({ 1.5,3.,3.5,1.,3.});
//     med_ans.push_back({ 2.5,3.,4.,1.,1.5});
//     return med_ans;
// }

void check(vector<vector<float>>& T1, vector<vector<float>>& T2) {
    int T1_size = T1.size();
    int T2_size = T2.size();
    if (T1_size != T2_size) {
        cout << "test failed" << endl;
        return ;
    }
    for (int i = 0; i < T1.size(); i++) {
        if (T1[i] == T2[i]) {
            cout << "T" << i << " check: Passed" << endl; 
        } else {
            cout << "T" << i << " check: Failed" << endl; 
        }
    }
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

void test() {

    showInformation();

    

}