/*
 * Other's Phone 
 * 
 * I don't find the origin problem in LeetCode,
 * so write it in this folder.
*/

/*
Print values and co-ordinates between 2 given co-ordinate points in a 2D array.

Input:
[[5, 2, 3],
 [4, 41, 2],
 [11, 34, 98]]
points = [1,2], [2,1]

Output: [2, 11, 34], co-ordinates = [[1, 2], [2, 0], [2,1]]
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> getElements(vector<vector<int>>& matrix, vector<int>& A, vector<int>& B) {
    vector<int> res;
    // vector<vector<int>> points;

    int colStart = 0, colEnd = 0;
    for (int row = A[0]; row <= B[0]; row++) {
        if (row == A[0]) colStart = A[1];
        else colStart = 0;
        if (row == B[0]) colEnd = B[1];
        else colEnd = matrix.size() - 1;

        for (int col = colStart; col <= colEnd; col++) {
            res.push_back(matrix[row][col]);
            // points.push_back({row, col});
        }
    }

    // for (auto x : points) cout << x[0] << " " << x[1] << endl;

    return res;
}

int main() {
    vector<int> temp;
    vector<vector<int>> matrix = {{5, 2, 3}, {4, 41, 2}, {11, 34, 98}};
    vector<int> A = {{1,2}};
    vector<int> B = {{2,1}};
    temp = getElements(matrix, A, B);

    for (auto x : temp) cout << x << endl;

    return 0;
}