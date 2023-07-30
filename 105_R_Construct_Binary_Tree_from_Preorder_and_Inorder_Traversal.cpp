/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
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
    //preorder and inorder consist of unique values.
    //so we may use hash map to store the value and position of inorder
    unordered_map<int, int>map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //Preorder: Root-Left-Right, Inorder: Left-Root-Right
        //credit to archit91
        //TC O(n), SC O(n)
        for(int i = 0;i < inorder.size(); i++)map[inorder[i]] = i;
        int n = inorder.size();
        int PreIdx = 0;
        return recur(preorder, inorder, 0, n - 1, PreIdx);
    }

    TreeNode* recur(vector<int>& preorder, vector<int>& inorder, int InStart, int InEnd, int& PreIdx){
        if(InStart > InEnd)return NULL; //base case

        //getting the new root from preorder
        TreeNode *root = new TreeNode(preorder[PreIdx++]);

        //using hash map to get the position of the node of the same value
        int InIdx = map[root->val];
        root->left = recur(preorder, inorder, InStart, InIdx-1, PreIdx);
        root->right = recur(preorder, inorder, InIdx + 1, InEnd, PreIdx);

        return root;
    }
};

class Solution {
public:
    /*
    preorder and inorder consist of unique values.
    so we may use hash map to store the value and position of inorder
    unordered_map<int, int>map;
    */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //Preorder: Root-Left-Right, Inorder: Left-Root-Right
        //credit to archit91
        //TC O(n^2), SC O(n)
        //for(int i = 0;i < inorder.size(); i++)map[inorder[i]] = i;
        int n = inorder.size();
        int PreIdx = 0;
        return recur(preorder, inorder, 0, n - 1, PreIdx);
    }

    TreeNode* recur(vector<int>& preorder, vector<int>& inorder, int InStart, int InEnd, int& PreIdx){
        if(InStart > InEnd)return NULL; //base case

        //getting the new root from preorder
        TreeNode *root = new TreeNode(preorder[PreIdx++]);

        //traverse to get the position of the node of the same value from inorder
        int InIdx = InStart;
        while(inorder[InIdx] != root->val)InIdx++;
        
        root->left = recur(preorder, inorder, InStart, InIdx-1, PreIdx);
        root->right = recur(preorder, inorder, InIdx + 1, InEnd, PreIdx);

        return root;
    }
};