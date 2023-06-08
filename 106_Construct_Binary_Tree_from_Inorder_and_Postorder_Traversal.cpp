/**
 * 
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 */
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //credit to suman_buie
        return backtrack(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* backtrack(vector<int>& inorder, int in_left, int in_right, vector<int>& postorder, int po_left, int po_right){
        if(in_left > in_right || po_left > po_right)return NULL;
        TreeNode* newRoot = new TreeNode(postorder[po_right]);
        int pivot = in_left;
        while(inorder[pivot] != postorder[po_right])pivot++;
        newRoot->left = backtrack(inorder, in_left, pivot-1, postorder, po_left, po_left + pivot - in_left - 1);
        newRoot->right = backtrack(inorder, pivot+1, in_right, postorder, po_left + pivot - in_left, po_right-1);
        return newRoot;
    }
};