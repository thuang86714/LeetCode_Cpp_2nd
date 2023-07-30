/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
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
    ListNode* partition(ListNode* head, int x) {
        //karan_8082
        ListNode* small_dummy = new ListNode(-1);
        ListNode* great_dummy = new ListNode(-1);
        ListNode* small_temp = small_dummy;
        ListNode* great_temp = great_dummy;

        //idea is create 2 sub-linked list then merge the smaller's tail to greater's head
        while(head){
            if(head->val < x){
                small_temp->next = head;
                small_temp = small_temp->next;
                head = head->next;
                small_temp->next = NULL;
            }else{
                great_temp->next = head;
                great_temp = great_temp->next;
                head = head->next;
                great_temp->next = NULL;
            }
        }
        small_temp-> next= great_dummy->next;

        return small_dummy->next;
    }
};