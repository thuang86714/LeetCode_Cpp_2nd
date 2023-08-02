/*
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane's algo
        //crdit to archit91, TC O(n), SC O(1)
        //it's safer to use nums[0], instead INT_MIN
        int curMax = 0, maxTillEnd = nums[0];
        for(int n:nums){
            curMax = max(n, n + curMax);
            maxTillEnd = max(curMax, maxTillEnd);
        }
        return maxTillEnd;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //credit to archit91, TC O(n), SC O(n)
        vector<int> dp(nums);
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};