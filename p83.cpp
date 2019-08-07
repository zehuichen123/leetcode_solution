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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        auto ptr = head->next;
        auto prev_node = head;
        while(ptr){
            if(ptr->val == prev_node->val){
                ptr = ptr->next;
                prev_node->next = ptr;
            }
            else{
                prev_node = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }
};