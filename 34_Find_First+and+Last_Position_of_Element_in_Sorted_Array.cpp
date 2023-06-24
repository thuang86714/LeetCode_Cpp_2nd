/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int l = 0, r = nums.size()-1, mid;
        while(l <= r){
            mid = (l + r)/2;
            if(nums[mid] < target)l = mid + 1;
            else{
                if(nums[mid] == target)result[0] = mid;//not a done deal yet, might go even more left
                r = mid-1;
            }
        }
        l = 0, r = nums.size()-1;
        while(l <= r){
            mid = (l + r)/2;
            if(nums[mid] > target)r = mid-1;
            else{
                if(nums[mid] == target)result[1] = mid;//not a done deal yet, might go even more right
                l = mid + 1;
            }
        }
        return result;
    }
};