class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //partial credit to archit91
        //recursive
        //TC O(n^2), SC O(n)
        int n = inorder.size();
        int PostIdx = n-1;
        return recur(inorder, 0, n-1, postorder, PostIdx);
    }
    TreeNode* recur(vector<int>& inorder, int InStart, int InEnd, vector<int>& postorder, int& PostIdx){
        if(InStart > InEnd)return NULL;
        TreeNode *root = new TreeNode(postorder[PostIdx--]);
        int pivot = InStart;
        while(inorder[pivot] != root->val)pivot++;
        
        root->right = recur(inorder, pivot+1, InEnd, postorder, PostIdx);
        root->left = recur(inorder, InStart, pivot-1, postorder, PostIdx);
        return root;
    }
};

class Solution {
public:
    //inorder and postorder consist of unique values.
    //we may use hashmap to store value and position of Inorder
    unordered_map<int, int>map;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //credit to archit91
        //TC O(n), SC O(n)
        for(int i = 0; i < inorder.size(); i++)map[inorder[i]] = i;
        int n = inorder.size();
        int PostIdx = n - 1;
        return recur(inorder, postorder, 0, n - 1, PostIdx);
    }

    TreeNode* recur(vector<int>& inorder, vector<int>& postorder, int InStart, int InEnd, int& PostIdx){
        if(InStart > InEnd)return NULL;//base case
        
        //Post-Order: Left-Right-Root
        TreeNode* root = new TreeNode(postorder[PostIdx--]);
        int InIdx = map[root->val];//no more traverse

        //the following two lines' order are not interchangeable, 
        //since Postorder is Left-Right-Root
        root->right = recur(inorder, postorder, InIdx+1, InEnd, PostIdx);
        root->left = recur(inorder, postorder, InStart, InIdx-1, PostIdx);

        return root;

    }
};