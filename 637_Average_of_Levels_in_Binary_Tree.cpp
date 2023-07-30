/*
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.

Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
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
    vector<double> averageOfLevels(TreeNode* root) {
        //BFS + vector
        queue<TreeNode*>q;
        q.push(root);

        //to store result of each level
        vector<double> result;

        while(!q.empty()){
            //to store sum of each level
             long int sum = 0;

            //to know the size of each level
            int q_size = q.size();

            for(int i = 0; i < q_size; i++){
                TreeNode *node = q.front();
                int temp = node->val;
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                sum += temp;
            }
            double avg = (double)sum/q_size;
            result.push_back(avg);
        }
        return result;
    }
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        //dfs
        //credit to jianchao li
        vector<int> counts;
        vector<double> avgs;
        average(root, counts, avgs, 0);
        for (int i = 0; i < avgs.size(); i++) {
            avgs[i] /= counts[i];
        }
        return avgs;
    }
private:
    void average(TreeNode* root, vector<int>& counts, vector<double>& sums, int l) {
        if (!root) {
            return;
        }
        if (counts.size() <= l) {
            counts.push_back({});
        }
        if (sums.size() <= l) {
            sums.push_back({});
        }
        counts[l]++;
        sums[l] += root -> val;
        average(root -> left, counts, sums, l + 1);
        average(root -> right, counts, sums, l + 1);
    }
};