/*Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(nums, result, temp, 0);
        return result;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, int idx){
        result.push_back(temp);
        for(int i = idx; i < nums.size(); i++){
            if(i == idx || nums[i] != nums[i-1]){
                temp.push_back(nums[i]);
                backtrack(nums, result, temp, i+1);
                temp.pop_back();
            }
        }
    }
};