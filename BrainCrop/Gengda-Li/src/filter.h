#ifndef FILTER_H
#define FILTER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef unsigned int size_t;

/**
 * inline function
 * 
 * calculate the medain
 * 
 * @param  {vector<float>} input : the sorted array
 * @param  {int} d               : the number of pervious scan D
 * @return {float}               : the median
 */
static inline float median(vector<float> &input, int d) {
	if (d >= input.size()) {
		if ((input.size() & 1) == 0) return (input[input.size()/2] + input[input.size()/2 - 1]) * 0.5;
 		else return input[input.size()/2];
	} else {
		if (((d+1) & 1) == 0) return (input[input.size() - d] + input[input.size() - d + 1]) * 0.5;
 		else return input[input.size() -d + 1];
	}
}

/**
 * class: filter
 * 
 * private: 
 * @param {float} min_range
 * @param {flaot} max_range
 * @param {int} D: the previous D scans
 *  
 */
class filter{
private:
	float min_range = 0.03;
	float max_range = 50.0;
	int D = 3;
public:
	filter(){}
	
	vector<float> range_filter(vector<float> &scan); 
	vector<float> temp_median_filter(vector<vector<float> > &data); 
	vector<float> gen_scan(int size); 
	void add_scan(vector<float> &scan, vector< vector<float> > &data); // Scans accumulation

	~filter(){}
};

/**
 * class: filter 
 * 
 * The range filter crops all the values that are below/above the min/max, and replace them with the min/max
 * 
 * @param  {vector<float>} scan : the input 
 * @return {vector<float>}      : the result
 */
vector<float> filter::range_filter(vector<float> &scan){
    vector<float> res;
    for (auto i : scan) {
        if (i < filter::min_range)      res.push_back(filter::min_range);
        else if (i > filter::max_range) res.push_back(filter::max_range);
        else                            res.push_back(i);
    }
    return res;
}

/**
 * class: filter 
 * 
 * A temporal median filter to calculate the median of the current element and previous D scans
 * 
 * @param  {vector<vector<float>} > : the input
 * @return {vector<float>}          : the result 
 */
vector<float> filter::temp_median_filter(vector<vector<float> > &data){
	int d = filter::D;
	vector<float> res(data.size(), 0);
	for (int i = 0; i < data.size(); i++){
		res[i] = median(data[i], d);
	}
	return res;
}

/**
 * class: filter 
 * 
 * generate random input, test function
 * 
 * @param  {int} size       : the input vector size
 * @return {vector<float>}  : 
 */
vector<float> filter::gen_scan(int size){
	if (size < 0 || size > 1000) {
		cout << "Input is out of range" << endl;
		exit(1);
	}
	vector<float> input(size, 0);
	for (int i = 0; i < size; i++){
		input[i] = rand() % 10;
	}
	return input;
}

/**
 * class: filter 
 * 
 * init the origin input vector or add a new vector to the origin
 * 
 * @param  {vector<float>} scan    : the new line
 * @param  {vector<} vector<float> : the input vector
 */
void filter::add_scan(vector<float> &scan, vector< vector<float> > &data){
	if (data.empty()){
		for (int i = 0; i < scan.size(); i++){
			data.push_back(vector<float>());
			data[i].push_back(scan[i]);
		}
	} else {
		for (int i = 0; i < scan.size(); i++){
			vector<float>::iterator it = lower_bound(data[i].begin(), data[i].end(), scan[i]);
			data[i].insert(it,scan[i]);
		}
	}
	return;
}

#endif