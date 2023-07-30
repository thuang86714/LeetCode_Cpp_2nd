/*
Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
    ListNode* rotateRight(ListNode* head, int k) {
        //credit to LeJas
        //edge case head == NULL
        if(!head)return NULL;
        ListNode *newHead = head, *tail = head;
        int count = 1;

        //count the len of the linked list
        while(tail->next){
            tail = tail->next;
            count++;
        }

        //circle up the linked list
        tail->next = head;

        //if k%len == 0, there's no shift
        if(k%=count){
            // the tail node is the (len-k)-th node (1st node is head)
            for(int i = 0; i < count - k; i++)tail = tail->next;
        }
        newHead = tail->next;
        tail->next = NULL;
        return newHead;
    }
};