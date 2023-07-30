/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.
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
    int countNodes(TreeNode* root) {
        //bfs with queue
        if(!root)return 0;
        queue<TreeNode *>q;
        q.push(root);
        //keep track of the number of nodes
        int count = 0;
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                TreeNode *node = q.front();
                q.pop();
                count++;

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            
            }
        }
        return count;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        //credit to vaibhav4859, the only possible TC less than O(n)
        if(!root)
            return 0;
        int lh = 0, rh = 0;
        TreeNode* l = root, *r = root;
        while(l){
            lh++;
            l = l->left;
        }
        while(r){
            rh++;
            r = r->right;
        }
        if(lh == rh)//because of this comparison, it's possible to be less than O(n)
            return pow(2, lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};