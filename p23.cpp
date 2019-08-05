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
    vector<ListNode*>ans;
    bool checkEmpty(vector<ListNode*> lists){
        for(auto i:lists){
            if(i != NULL){
                return false;
            }
        }
        return true;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ptr = new ListNode(0);
        ListNode* first = ptr;
        while(!checkEmpty(lists)){
            ListNode* small = new ListNode(0x7fffffff);
            int small_index = -1;
            for(int i=0; i<lists.size(); i++){
                if(lists[i] != NULL){
                    if(lists[i]->val < small->val){
                        small->val = lists[i]->val;
                        small_index = i;
                    }
                }
            }
            ptr->next = lists[small_index];
            ptr = ptr->next;
            lists[small_index] = lists[small_index]->next;
        }
        return first->next;
    }
};