/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //nth node from "the end"
        //could be the head of the linked list
        //with unordered_map<int, ListNode*> we could do O(n)
        //edge case1: sz ==1
        if(!head->next)return NULL;

        //unordered_map to record position of each node
        unordered_map<int, ListNode*> map;
        
        //record current position, we assume 0-indexed
        int count = 0;

        //need a dummy in case of removing the head of the linked list
        ListNode dummy(0);
        dummy.next = head;

        //need a temp to traverse
        ListNode *temp = head;

        while(temp){
            map[count] = temp;
            if(temp->next){
                temp = temp->next;
                count++;
            }else{
                break;
            }
            
        }

        //make the (n-1) node point to (n+1)node, 
        //but be careful when count < n, we need to remove the head
        if(count < n){//removing the head
            dummy.next = map[1];
        }else if(n == 1){
            map[count - n]->next = NULL;
        }else{
            map[count - n]->next = map[count - n + 2];
        }
        return dummy.next;
    }
};