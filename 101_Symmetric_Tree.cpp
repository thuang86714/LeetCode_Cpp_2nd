/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Input: root = [1,2,2,3,4,4,3]
Output: true

Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
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
    bool isSymmetric(TreeNode* root) {
        //recur
        if(root ==NULL)return true;
        return recur(root->right, root->left);
    }
    bool recur(TreeNode* R, TreeNode* L){
        if(!R && !L)return true;
        if(!R || !L)return false;
        if(R->val != L->val)return false;
        return recur(R->right, L->left)&&recur(L->right, R->left);
    }
};

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
    bool isSymmetric(TreeNode* root) {
        //BFS iterativly
        //credit to aryan_0077
        if(!root)return true;

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()){
            TreeNode *Left = q.front();
            q.pop();
            TreeNode* Right = q.front();
            q.pop();

            if(!Right && !Left)continue;
            if(!Right || !Left || Left->val != Right->val)return false;
            q.push(Left->left);
            q.push(Right->right);
            q.push(Left->right);
            q.push(Right->left);
        }
        return true;
    }
};
