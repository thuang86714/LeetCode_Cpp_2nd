/*

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //credit to jianchao-li
        //TC O(m*n), SC O(m*n)
        int m = matrix.size(), n = matrix[0].size(), size = 0;
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0 || matrix[i][j] == '0'){
                    dp[i][j] = matrix[i][j]-'0';
                }else{
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                size = max(size, dp[i][j]);
            }
        }
        return size*size;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //TC O(m*n), SC O(2n)
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<int> pre(n, 0), cur(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    cur[j] = matrix[i][j] - '0';
                } else {
                    cur[j] = min(pre[j - 1], min(pre[j], cur[j - 1])) + 1;
                }
                sz = max(cur[j], sz);
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return sz * sz;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //TC O(m*n), SC O(n)
        if(matrix.empty())return 0;
        int m = matrix.size(), n = matrix[0].size(), size = 0, pre;
        vector<int> cur(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int temp = cur[j];
                if(i ==0 || j == 0 || matrix[i][j] == '0'){
                    cur[j] = matrix[i][j] - '0';
                }else{
                    cur[j] = min(pre, min(cur[j - 1], cur[j])) + 1;
                }
                size = max(size, cur[j]);
                pre = temp;
            }
        }
        return size*size;
    }
};