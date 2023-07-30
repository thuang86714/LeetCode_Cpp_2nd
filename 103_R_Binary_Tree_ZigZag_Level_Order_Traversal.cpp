/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>> result;
        while(!q.empty()){
            int q_size = q.size();
            vector<int> temp;
            for(int i = 0; i < q_size; i++){
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);
                //from left to right, level by level
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            result.push_back(temp);
        }
        for(int i = 1; i < result.size(); i++){
            if(i%2){
                reverse(result[i].begin(), result[i].end());
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        backtrack(root, 0);
        for(int i = 1; i < result.size(); i = i+2){
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
    void backtrack(TreeNode* root, int depth){
        if(!root)return;
        if(result.size() == depth){
            result.push_back(vector<int>());
        }
        result[depth].push_back(root->val);
        backtrack(root->left, depth+1);
        backtrack(root->right, depth+1);
    }
};