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
    ListNode* swapPairs(ListNode* head) {
        auto ans = new ListNode(-1);
        auto prev = ans;
        ans->next = head;
        auto ptr1 = head;
        if(ptr1 == NULL){
            return NULL;
        }
        auto ptr2 = ptr1->next;
        ListNode* next_first = NULL;
        while(ptr2 != NULL && ptr1 != NULL){
            next_first = ptr2->next;
            prev->next = ptr2;
            ptr2->next = ptr1;
            prev = ptr1;
            ptr1 = next_first;
            if(ptr1 != NULL){
                ptr2 = next_first->next;
            }
        }
        if(ptr1 == NULL){
            prev->next = NULL;
            return ans->next;
        }
        else{
            prev->next = ptr1;
            ptr1->next = NULL;
            return ans->next;
        }
    }
};