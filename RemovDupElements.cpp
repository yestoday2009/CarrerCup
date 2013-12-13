//Remove Duplicates from Sorted List

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* p = head;
        ListNode* tempHead = head;
        int value = head->val;
        head = head->next;
        while (head != NULL){
            if(head->val != value){
                value = head->val;
                p->next = head;
                p = head;
            }
            head = head->next;
        }
        p->next = head;
        
        return tempHead;
    }
};