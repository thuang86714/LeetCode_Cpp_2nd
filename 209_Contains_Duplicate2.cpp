/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //brute force: nested for loop O(n^2)
        //with hasp map, we can do O(n)
        //edge case1: k == 0, return false;
        if(k == 0)return false;
        unordered_map<int, int> visited;//<nums[i], i>
        for(int i = 0; i < nums.size(); i++){
            if(visited.find(nums[i]) != visited.end()){
                if(abs(visited[nums[i]] - i) <= k)return true;
            }
            visited[nums[i]] = i;//we could update this because currently i - j > k, so by updating this key-value pair, we may get smaller result
        }
        return false;
    }
};