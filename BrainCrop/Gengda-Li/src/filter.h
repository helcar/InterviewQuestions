#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

/**
 * 
 * @param  {vector<float>} data : 
 * @return {float}              : 
 */
static inline float median(vector<float> &data) {
	int size = data.size();
	if ((size & 1) == 0) return (data[size/2] + data[size/2 - 1]) * 0.5;
	else return data[size/2];
}

class Filter {
private:
	float min_range = 0.03;
	float max_range = 50;
	int D = 3;
	vector<vector<float>> transpose(vector<vector<float>>& A);
	vector<float> range_filter(vector<float>& scan);
	vector<vector<float>> temp_med_filter(vector<vector<float>>& temp, vector<vector<float>>& input, int d);
	bool judgeSize(vector<vector<float>>& input);
public:
	Filter(){}
	vector<vector<float>> range_update(vector<vector<float>>& input);
	vector<vector<float>> temp_med_update(vector<vector<float>>& input);
	~Filter(){}
};

/**
 * Filter 
 * 
 * @param  {vector<vector<float>>} input : 
 * @return {bool}                        : 
 */
bool Filter::judgeSize(vector<vector<float>>& input) {
	if (input.empty()) return false;
	if (input[0].size() > 1000) return false;
	return true;
}

/**
 * Filter 
 * 
 * @param  {vector<float>} scan : 
 * @return {vector<float>}      : 
 */
vector<float> Filter::range_filter(vector<float>& scan) {
	vector<float> res;
	float min = 0.03;
	float max = 50;
    for (auto i : scan) {
        if (i < min)      res.push_back(min);
        else if (i > max) res.push_back(max);
        else              res.push_back(i);
    }
    return res;
}

/**
 * Filter 
 * 
 * @param  {vector<vector<float>>} input : 
 * @return {vector<vector<float>>}       : 
 */
vector<vector<float>> Filter::range_update(vector<vector<float>>& input) {
	if (judgeSize(input) == false) exit(1);
	cout << "The Range_Filter Runs" << endl;
	vector<vector<float>> range_res;
	for (int i = 0; i < input.size(); i++) range_res.push_back(range_filter(input[i]));
	return range_res;
}

/**
 * Filter 
 * 
 * @param  {vector<vector<float>>} A : 
 * @return {vector<vector<float>>}   : 
 */
vector<vector<float>> Filter::transpose(vector<vector<float>>& A)  {
    int m=A.size();
    int n=A[0].size();
    vector<vector<float>> res(n);
    for(float i=0;i<n;i++) res[i].resize(m); 
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            res[i][j]=A[j][i];
        }
    }
    return res;
}

/**
 * Filter 
 * 
 * @param  {vector<vector<float>>} temp  : 
 * @param  {vector<vector<float>>} input : 
 * @param  {int} d                       : 
 * @return {vector<vector<float>>}       : 
 */
vector<vector<float>> Filter::temp_med_filter(vector<vector<float>>& temp, vector<vector<float>>& input, int d) {
	vector<vector<float>> med_res(input.size(), vector<float>(input[0].size()));
	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < temp[0].size(); j++) {
			vector<float> t;
			int bound = (j - d <= 0) ? 0 : j - d;
			int jj = j;
			while (jj >= bound) t.push_back(temp[i][jj--]);
			sort(t.begin(), t.end());
			med_res[j][i] = median(t);
		}
	}
	return med_res;
}

/**
 * Filter 
 * 
 * @param  {vector<vector<float>>} input : 
 * @return {vector<vector<float>>}       : 
 */
vector<vector<float>> Filter::temp_med_update(vector<vector<float>>& input) {
	if (judgeSize(input) == false) exit(1);
	cout << "The Temporal_Median_Filter Runs" << endl;
	int d = Filter::D;
	vector<vector<float>> temp = transpose(input);
	vector<vector<float>> med_res = temp_med_filter(temp, input, d);
	return med_res;
}