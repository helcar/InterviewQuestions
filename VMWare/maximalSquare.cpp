#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int helper(vector<vector<char>> &matrix, int r, int c) {
    int row = r - 1, col = c - 1;
    while (row >= 0 && col >= 0 && matrix[r][col] == '1' && matrix[row][c] == '1') {
        int i = row, j = col;
        while (i < r && matrix[i][col] == '1') i++;
        while (j < c && matrix[row][j] == '1') j++;
        if (i != r || j != c) break;
        row--, col--;
    }
    return pow(r - row, 2);
}

int maximalSquare(vector<vector<char>> &matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    int res = 0;
    for (int i = 0 ; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') res = max(res, helper(matrix, i, j));
        }
    }
    return res;
}