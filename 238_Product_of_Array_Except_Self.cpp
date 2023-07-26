/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //brute force O(n^2)
        //careful nums[i] could be negative or 0
        //TC O(n), SC O(1)
        int prefix = 1, postfix = 1;
        vector<int> result(nums.size());
        for(int i= 0; i < nums.size(); i++){
            result[i] = prefix;
            prefix *= nums[i];
        }
        for(int j = nums.size()-1; j >= 0; j--){
            result[j] *= postfix;
            postfix *= nums[j];
        }
        return result;

    }
};