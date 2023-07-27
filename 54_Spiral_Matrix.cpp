/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //credit to techwired8
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        vector<int> result;
        while(left <= right && top <= bottom){

            //going right
            for(int i = left; i <= right && top<=bottom; i++)result.push_back(matrix[top][i]);
            top++;

            //going down
            for(int i = top; i <= bottom && left<=right; i++)result.push_back(matrix[i][right]);
            right--;
            
            //going left
            for(int i = right; i >= left && top<=bottom; i--)result.push_back(matrix[bottom][i]);
            bottom--;

            //going up
            for(int i = bottom; i >= top && left<=right; i--)result.push_back(matrix[i][left]);
            left++;//going into next spiral if necessary
            
        }
        return result;
    }
};