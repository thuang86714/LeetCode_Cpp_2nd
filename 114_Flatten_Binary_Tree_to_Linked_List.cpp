/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
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
    void flatten(TreeNode* root) {
        //credit to zjulyx && StefanPochmann
        //TC O(n), SC O(1)
        TreeNode* now = root;
        while(now){
            if(now->left){
                TreeNode* prev = now->left;
                while(prev->right)prev = prev->right;
                prev->right = now->right;
                now->right = now->left;
                now->left = NULL; 
            }
            now = now->right;
        }
        /*
        Time is O(n), here's why:
        You're moving now over all nodes and for each one potentially dive
         down deep into its left subtree, so one might think it's more than O(n) time. 
        But... a long path down the left subtree immediately pays off, as you then insert 
        that entire path into the "right border" of the whole tree, 
        where now will walk over it once more but pre will never have to walk over it again.
        To put it differently: Every node is visited by now exactly once and by pre at most once,
         and the runtime is proportional to the number of steps taken by now and pre, 
        so O(n) overall.*/
    }
};