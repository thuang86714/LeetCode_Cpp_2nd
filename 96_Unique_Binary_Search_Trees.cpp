/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n
Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
*/
class Solution {
public:
    int dp[20]{};//20 because the constraint of n is 0 <= n <=19
    int numTrees(int n) {
        if(n <= 1)return 1;//base case 1
        if(dp[n])return dp[n];//base case2
        for(int i =1; i <= n; i++){
            dp[n] += numTrees(i-1)*numTrees(n-i);
        }
        return dp[n];
    }
};