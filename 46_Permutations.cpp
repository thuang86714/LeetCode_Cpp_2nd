/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        recur(result, nums, 0);
        return result;
    }
    void recur(vector<vector<int>>& result, vector<int> nums, int idx){
        //base case
        if(idx == nums.size()){
            result.push_back(nums);
        }
        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            recur(result, nums, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
};