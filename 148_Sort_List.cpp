/*
Given the head of a linked list, return the list after sorting it in ascending order.
Input: head = [4,2,1,3]
Output: [1,2,3,4]
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
    ListNode* sortList(ListNode* head) {
        //credit to KnockCat
        //first we use turtle-hare algo to find the mid point
        if(!head || !head->next)return head;
        ListNode *slow = head, *fast = head, *temp = head;
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;//at this point, temp is the last node in the first-half linked list
        //and slow is the first node in the second-half linked list
        ListNode *L1 = sortList(head);//recursive call for the first half, by recursive, we are doind divide and conquer
        ListNode *L2 = sortList(slow);//recursive call for the second half
        return mergeList(L1,L2);
    }

    ListNode* mergeList(ListNode* L1, ListNode* L2){
        //we assume the 0 < =|first-half.size()-second-half.size()| <=1
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while(L1 && L2){
            if(L1->val < L2->val){
                cur->next = L1;
                L1 = L1->next;
            }else{
                cur->next = L2;
                L2 = L2->next;
            }
            cur = cur->next;
        }
        //But be careful, one linked list may be longer than the other one by one node
        if(L1){
            cur->next = L1;
            L1 = L1->next;
        }
        if(L2){
            cur->next = L2;
            L2 = L2->next;
        }
        return dummy->next;
    }
};