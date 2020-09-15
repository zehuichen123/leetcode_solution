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

// second solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // first head node
        auto start = new ListNode(0);
        start->next = head;
        // quick
        auto ptr1 = start;
        // slow
        auto ptr2 = start;
        
        for(int i=0; i<n; i++){
            ptr1 = ptr1->next;
        }
        while(ptr1->next){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        auto prev = ptr2;
        ptr2 = ptr2->next;
        ptr2 = ptr2->next;
        prev->next = ptr2;
        return start->next;
    }
};