LIDAR Filter
========

LIDAR Filter will provide you with useful functions to reduce noise in the data coming from a LIDAR sensor
attached to your robot. LIDAR filter provides two filters entitled as range and temporal median.

To use this software:

To use range filter, you should define an array of sensor measurements as a two-dimensional vector.
Example:
    

    // Example input matrix
	vector<vector<float>> input;
	input.push_back({ 0.,1.,2.,1.,3. });
	input.push_back({ 1.,5.,7.,1.,3. });
	input.push_back({ 2.,3.,4.,1.,0. });
	input.push_back({ 3.,3.,3.,1.,3. });
	input.push_back({ 10.,2.,4.,0.,0. });

    // Range Filter 
    Filter F1;   // define the filter
    vector<vector<float>> range_res = F1.range_update(input);  // run the range filter
    print(range_res);   // print the range filter results

    
To use temporal median filter, you should define a two-dimensional data up to current scan.
Example:


    // Temporal median filter
    Filter F2;  // define the filter
    vector<vector<float>> med_res = F2.temp_med_update(input);   // run the temporal median filter
    print(med_res);   // print the temporal median filter results


Tests
--------
Testcases are located inside the Test directory which includes:

	-- Problem sample 
	-- Update with 20 number of random scans each with 10 measurements

	-- Empty sample: because I have handled the empty input in the filter functions

To run all testcases, simply compile and execute run.cpp located inside the Run directory.
	
Installation
--------
Copy filters.h from src directory from Test directory file located inside src folder into your main running code. Then add the file as a header:

    #include "filters.h"


