/*
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

A subarray is that a continuous non-empty of elements within that array

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //it's a dp problem, here we present space optimized version SC O(1);
        if(nums.empty())return 0;
        int MAX = INT_MIN;
        int cur_Max = 1;
        int cur_Min = 1;//this exists for the negatives int in the nums;
        for(auto n: nums){
            if(n<0){
                swap(cur_Max, cur_Min);
            }
            cur_Max = max(cur_Max*n, n);
            cur_Min = min(cur_Min*n, n);
            MAX = max(cur_Max, MAX);
        }
        return MAX;
    }
};