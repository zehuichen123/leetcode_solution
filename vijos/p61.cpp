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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* prev = NULL;
        if(head==NULL){
            return head;
        }
        int len = 0;
        while(ptr != NULL){
            prev = ptr;
            ptr = ptr->next;
            len += 1;
        }
        prev->next = head;
        ptr = head;
        k = k % len;
        for(int i=0; i<len-k; i++){
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        return ptr;
    }
};