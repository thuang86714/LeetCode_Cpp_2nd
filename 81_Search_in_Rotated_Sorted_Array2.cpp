/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //binary search, credit to KnockCat
        int left = 0, mid, right = nums.size()-1;
        while(left <= right){
            mid = (left + right)/2;
            if (nums[mid] == target)return true;
    
            //the only difference from the Search in Rotated Array1 is the trickly case(may not necessarily with distinct values). In this case, just update left and right
            if (nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
                right--;
            // first half
			// first half is in order
            }else if (nums[left] <= nums[mid]){
                if((nums[left] <= target)&&(nums[mid] > target)){
                    right = mid-1;
                }else{
                    left = mid +1;
                }
            // second half
			// second half is in order
            }else{
                if((nums[mid] < target)&&(nums[right] >= target)){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return false;
    }
};