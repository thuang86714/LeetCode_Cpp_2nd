/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:
*/
class Solution {
public:
    //credit to samoshka
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recur(nums, 0, nums.size());
    }
    TreeNode* recur(vector<int>& nums, int start, int end){
        if(start >= end)return NULL;
        int mid = (start + end)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = recur(nums, start, mid);
        root->right = recur(nums, mid+1, end);
        return root; 
    }
};