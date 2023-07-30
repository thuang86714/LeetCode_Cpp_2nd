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
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
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
    vector<int> rightSideView(TreeNode* root) {
        //intuition BFS
        if(!root)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        while(!q.empty()){
            int q_size = q.size();
            TreeNode *node = q.front();
            q.pop();
            result.push_back(node->val);
            if(node->right)q.push(node->right);
            if(node->left)q.push(node->left);
            for(int i = 0; i < q_size-1; i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->right)q.push(temp->right);
                if(temp->left)q.push(temp->left);
            }

        }
        return result;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //dfs
        //credit to jianchao li
        vector<int> view;
        rightView(root, view, 0);
        return view;
    }
private:
    void rightView(TreeNode* root, vector<int>& view, int level) {
        if (!root) {
            return;
        }
        if (view.size() == level) {
            view.push_back(root -> val);
        }
        rightView(root -> right, view, level + 1);
        rightView(root -> left, view, level + 1);
    }
};