/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //do remember the right node might be absent, then left node would fill the seat
        int level = 1;
        vector<int> result;
        recur(root, level, result);
        return result;
    }
    void recur(TreeNode* root, int level, vector<int>& result){
        if(!root)return;//as the base case
        if(result.size() < level)result.push_back(root->val);//another base case
        recur(root->right, level+1, result);
        recur(root->left, level+1, result);
    }
};