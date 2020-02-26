#ifndef TEST_H
#define TEST_H

#include <string>



/**
 * class: testcase
 * 
 * test class
 * 
 * @param {string}name : the case name 
 */
class testcase{
private:
	string name;
public:
	vector<vector<float> > data;
	vector<float> scan;
	vector<float> med_out;
	vector<float> range_out;
	testcase(string name):name(name){}
	string get_name(){
		return name;
	}
	void set_name(string input){
		name = input;
	}
	~testcase(){}
};

struct Test{
	void check_FD(filter &L, testcase &T); 
	void check_temp(filter &L, size_t D); 
	vector<testcase> Build_FD();
	void rand_update(filter &L, size_t N, size_t D); 
	void tests();
};

/**
 * class: Test 
 * 
 * check the test case's correctness
 * 
 * @param  {filter} L   
 * @param  {testcase} T 
 */
void Test::check_FD(filter &L, testcase &T) {
	if (L.temp_median_filter(T.data) == T.med_out &&
		L.range_filter(T.scan) == T.range_out){
		cout << T.get_name() << ": Passed \n";
	}
	else cerr << T.get_name() << ": Failed \n";
}

/**
 * class: Test 
 * 
 * @param  {filter} L 
 * @param  {size_t} D 
 */
void Test::check_temp(filter &L, size_t D) {
	testcase* temp = new testcase(" ");
	temp->scan.resize(1e3, 0.1);
	temp->med_out = temp->scan;
	temp->range_out = temp->scan;
	for (size_t i = 0; i < D; i++){
		L.add_scan(temp->scan, temp->data);
		string str = "1000 measurements T";
		string index = to_string(i);
		str += index;
		temp->set_name(str);
		if (i == D - 1) check_FD(L, *temp);
	}
	delete temp;
}

/**
 * class: Test 
 * 
 * generate the testcases
 * 1. Empty
 * 2. 1e30
 * 3. File 
 * 
 * @return {vector<testcase>}  : 
 */
vector<testcase> Test::Build_FD() {
	filter L;
	vector<testcase> FD_scans;
	testcase triv0("Empty case");
	triv0.scan = {};
	triv0.med_out = {};
	triv0.range_out = {};
	L.add_scan(triv0.scan, triv0.data);

	testcase triv1("1e30 reading values");
	triv1.scan = {-1e30, 60, 1e30};
	triv1.med_out = {-1e30, 60, 1e30};
	triv1.range_out = {0.03, 50, 50};
	L.add_scan(triv1.scan, triv1.data);

	FD_scans.push_back(triv0);
	FD_scans.push_back(triv1);

	testcase T0("Problem example T0 update");
	T0.scan = {0., 1., 2., 1., 3.};
	T0.med_out = {0, 1., 2., 1., 3.};
	T0.range_out = {0.03, 1., 2., 1., 3.};

	testcase T1("Problem example T1 update");
	T1.scan = {1., 5., 7., 1., 3.};
	T1.med_out = {0.5, 3., 4.5, 1., 3.};
	T1.range_out = {1., 5., 7., 1., 3.};

	testcase T2("Problem example T2 update");
	T2.scan = {2., 3., 4., 1., 0.};
	T2.med_out = {1., 3., 4., 1., 3.};
	T2.range_out = {2., 3., 4., 1., 0.03};

	testcase T3("Problem example T3 update");
	T3.scan = {3., 3., 3., 1., 3.};
	T3.med_out = {1.5, 3., 3.5, 1., 3.};
	T3.range_out = {3., 3., 3., 1., 3.};

	testcase T4("Problem example T4 update");
	T4.scan = {10., 2., 4., 0., 0.};
	T4.med_out = {2., 3., 4., 1., 3.};
	T4.range_out = {10., 2., 4., 0.03, 0.03};

    for (size_t i = 0; i < 5; i++) {
        switch (i) {
			case 0:
				L.add_scan(T0.scan, T0.data);
				FD_scans.push_back(T0);
				break;
			case 1:
				L.add_scan(T1.scan, T0.data);
				T1.data = T0.data;
				FD_scans.push_back(T1);
				break;
			case 2:
				L.add_scan(T2.scan, T1.data);
				T2.data = T1.data;
				FD_scans.push_back(T2);
				break;
			case 3:
				L.add_scan(T3.scan, T2.data);
				T3.data = T2.data;
				FD_scans.push_back(T3);
				break;
			case 4:
				L.add_scan(T4.scan, T3.data);
				T4.data = T3.data;
				break;
			default:
				break;
        }
    }
	return FD_scans;
}

/**
 * class: Test 
 * 
 * generate random testcases
 * 
 * @param  {filter} L : filter object
 * @param  {size_t} N : row size
 * @param  {size_t} D : col size
 */
void Test::rand_update(filter &L, size_t N, size_t D) {
	testcase* temp = new testcase(" ");
	string str = "Update filter N = ";
	str = str + to_string(N) + ", D = " + to_string(D);
	temp->set_name(str);
	cout << temp->get_name() << endl;

	vector<vector<float>> container;
	vector<vector<float>> medRes;
	vector<vector<float>> rangeRes;

	for (int i = 0; i < D; i++) {
		temp->scan = L.gen_scan(N);
		L.add_scan(temp->scan, temp->data);
		temp->med_out = L.temp_median_filter(temp->data);
		temp->range_out = L.range_filter(temp->scan);
		container.push_back(temp->scan);
		medRes.push_back(temp->med_out);
		rangeRes.push_back(temp->range_out);
	}
	cout << "The input is: " << endl;
	for (int i = 0; i < container.size(); i++) {
		for (int j = 0; j < container[0].size(); j++) {
			cout << container[i][j] << "\t";
		}
		cout << " " << endl;
	}
	cout << " " << endl;
	cout << "The med is: " << endl;
	for (int i = 0; i < medRes.size(); i++) {
		for (int j = 0; j < medRes[0].size(); j++) {
			cout << medRes[i][j] << "\t";
		}
		cout << " " << endl;
	}
	cout << " " << endl;
	cout << "The range is: " << endl;
	for (int i = 0; i < rangeRes.size(); i++) {
		for (int j = 0; j < rangeRes[0].size(); j++) {
			cout << rangeRes[i][j] << "\t";
		}
		cout << " " << endl;
	}

	delete temp;
	return;
}

/**
 * Test 
 * 
 */
void Test::tests() {

	cout << "Test case is running" << endl;
	cout << " " << endl;
	filter L;
	Test test;
	try {
		test.Build_FD();
	}
	catch(bad_alloc &e){
		cerr << "Error: Out of memory - Please reduce the size of the largest variable" << endl;
		return;
	}
	vector<testcase> FD_scans = test.Build_FD();
	for (size_t i = 0; i < FD_scans.size(); i++){
		test.check_FD(L, FD_scans[i]);
	}
	test.check_temp(L, 1000);
	test.rand_update(L, 20, 20);
	return;
}



#endif