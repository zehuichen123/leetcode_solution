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
    int getLen(ListNode* head){
        int count = 0;
        while(head != NULL){
            count += 1;
            head = head->next;
        }
        return count;
    }
    ListNode* reverseSingleGroup(ListNode* head, int k){
        if(getLen(head) < k){
            return head;
        }
        auto ptr1 = head;
        auto ptr2 = head;
        auto prev = new ListNode(-1);
        for(int i=0; i<k; i++){
            ptr2 = ptr1->next;
            ptr1->next = prev;
            prev = ptr1;
            ptr1 = ptr2;
        }
        head->next = reverseSingleGroup(ptr1, k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseSingleGroup(head, k);
    }
};