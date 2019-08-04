// Given a linked list, remove the n-th node from the end of list and return its head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:

// Given n will always be valid.

// Follow up:

// Could you do this in one pass?

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
    int getLength(ListNode* head){
        int count = 0;
        while(head != NULL){
            count += 1;
            head = head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLength(head);
        if(len == n){
            return head->next;
        }
        auto ptr = head;
        for(int i=0; i<len-n-1; i++){
            ptr = ptr->next;
        }
        auto prev = ptr;
        ptr = ptr->next;
        ptr = ptr->next;
        prev->next = ptr;
        return head;
    }
};