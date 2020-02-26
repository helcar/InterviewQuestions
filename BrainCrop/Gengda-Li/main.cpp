#include "src/filter.h"
#include "Test/test.h"

using namespace std;

void example_file() {
	vector<vector<float>> input;
	input.push_back({ 0.,1.,2.,1.,3. });
	input.push_back({ 1.,5.,7.,1.,3. });
	input.push_back({ 2.,3.,4.,1.,0. });
	input.push_back({ 3.,3.,3.,1.,3. });
	input.push_back({ 10.,2.,4.,0.,0. });
	vector<vector<float>> med_ans;
    med_ans.push_back({ 0.,1.,2.,1.,3. });
    med_ans.push_back({ 0.5,3,4.5,1.,3. });
    med_ans.push_back({ 1.,3.,4.,1.,3.});
    med_ans.push_back({ 1.5,3.,3.5,1.,3.});
    med_ans.push_back({ 2.5,3.,4.,1.,1.5});
	Filter F2;
	vector<vector<float>> example_med_res = F2.temp_med_update(input);
	check(med_ans, example_med_res);
}

int main() {

	statement();
	example_file();
	vector<vector<float>> input;
	input = gen_random_test(10, 20, 100);
	print(input);
	Filter F1;
	vector<vector<float>> med_res = F1.temp_med_update(input);
	print(med_res);
	vector<vector<float>> range_res = F1.range_update(input);
	print(range_res);

	return 0;
}
