/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //SC O(1), TC O(n)
        //different from the last one: this time, it's not guranteed that all tree are perfect binary tree
        if(!root)return NULL;
        queue<Node*> q;//queue FIFO
        q.push(root);
        while(!q.empty()){
            Node* rightnode = NULL;
            int q_size = q.size();//meant in the for loop next line, q.size() is a fixed number
            for(int i = q_size; i > 0; i--){
                Node* cur = q.front();
                q.pop();
                cur->next = rightnode;
                rightnode = cur;//at the same level, rightnode is moving left
                if(cur->right){//queue FIFO
                    q.push(cur->right);
                }
                if(cur->left){
                    q.push(cur->left);
                }
            }
        }
        return root;
    }
};