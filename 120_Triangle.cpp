/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n ==1)return triangle[0][0];
        vector<int> dp(triangle.back());/*dp would store every pathsum of every path, we directly store the lowest layer into dp as the base case to start*/
        for(int layer = n -2; layer >= 0; layer--){
            for(int i = 0; i <= layer; i++){
                dp[i] = min(dp[i], dp[i+1]) + triangle[layer][i];
            }
        }
        return dp[0];
    }
};