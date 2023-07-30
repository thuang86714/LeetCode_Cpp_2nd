/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //merge in mergeSort
        //careful with the unequal length
        //TC O(max(list1.len, list2.len)), SC O(max(list1.len, list2.len))
        ListNode result(0);
        ListNode *temp = &result;

        //we will traverse both lists, add the cur smaller element to the new linked list
        while(list1 || list2){
            //if both list not reach the end yet
            if(list1 && list2){
                if(list1->val > list2->val){
                    temp->next = new ListNode(list2->val);
                    temp = temp->next;
                    list2 = list2->next;
                }else{
                    temp->next = new ListNode(list1->val);
                    temp = temp->next;
                    list1 = list1->next;
                }
                
            }else if(list1){//if list1 is longer
                temp->next = new ListNode(list1->val);
                temp = temp->next;
                list1 = list1->next;

            }else{//if list2 is longer
                temp->next = new ListNode(list2->val);
                temp = temp->next;
                list2 = list2->next;
            }
        }
        return result.next;
    }
};