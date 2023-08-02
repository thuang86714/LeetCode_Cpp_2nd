/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

Input: root = [4,2,6,1,3]
Output: 1

Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105
*/
class Solution {
public:
    int diff = INT_MAX;
    TreeNode *prev = NULL;
    int getMinimumDifference(TreeNode* root) {
        //intuition bfs + vector + sorting
        //not using BST In-order(left-Root-Right) traversal of BST yields sorted sequence.
        //if we could fully leverage the BST, TC O(h), where h is height
        //credit to Ajna
        dfs(root);
        return diff;
    }
    void dfs(TreeNode *root) {
        // moving to the left as much as we can
        if (root->left) dfs(root->left);
        // if we find at least a node before, we update diff
        if (prev) diff = min(diff, abs(prev->val - root->val));
        prev = root;
        // moving to the right as much as we can
        if (root->right) dfs(root->right);
    }
    
};

//equivalent, credit to votrubac
class Solution{
    int inorderTraverse(TreeNode* root, int& val, int& min_dif) {
        if (root->left != NULL)
            inorderTraverse(root->left, val, min_dif);
        if (val >= 0) 
            min_dif = min(min_dif, root->val - val);
        val = root->val;
        if (root->right != NULL) 
            inorderTraverse(root->right, val, min_dif);
        return min_dif;
    }
    int getMinimumDifference(TreeNode* root) {
        auto min_dif = INT_MAX, val = -1;
        return inorderTraverse(root, val, min_dif);
    }
};