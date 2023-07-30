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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)return NULL;

        TreeNode *temp_left = root->left, *temp_right = root->right;
        
        root->right = invertTree(temp_left);
        root->left = invertTree(temp_right);
        return root;
        /*
        credit to jmarloch
        you can find the problem size that will overflow the stack and crash your application), so more robust solution would be to use stack data structure*/
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //edge case1: root == NULL;
        if(!root)return NULL;
        //BFS
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            TreeNode * temp = node->left;
            node->left = node->right;
            node->right = temp;

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }

        return root;

    }
};