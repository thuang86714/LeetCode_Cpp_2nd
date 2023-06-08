/*
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
Example:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]
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
    vector<TreeNode*> generateTrees(int n) {
        //credit to sxycwzwzq
        if (n ==0)return vector<TreeNode*>(0);
        return backtrack(1, n);
    }
    vector<TreeNode*> backtrack(int from, int to){
        vector<TreeNode*> result;
        if(from > to){
            result.push_back(NULL);
            return result;
        }
        for(int i = from; i <= to; i++){
            vector<TreeNode*> Lefttree = backtrack(from, i-1);
            vector<TreeNode*> Righttree = backtrack(i+1, to);
            for(int j = 0; j < (int)Lefttree.size(); j++){
                for(int k = 0; k < (int)Righttree.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = Lefttree[j];
                    root->right = Righttree[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};