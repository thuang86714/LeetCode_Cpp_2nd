/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return backtrack(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
    TreeNode* backtrack(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right){
        if(left > right)return NULL;//base case
        int pivot = left;
        while(inorder[pivot] != preorder[rootIdx])pivot++;
        rootIdx++;
        TreeNode* newRoot = new TreeNode(inorder[pivot]);
        newRoot->left = backtrack(preorder, inorder, rootIdx, left, pivot-1);
        newRoot->right = backtrack(preorder, inorder, rootIdx, pivot+1, right);//at this point, the rootIdx here is the rootIdx from the last line +1
        return newRoot;
    }
};