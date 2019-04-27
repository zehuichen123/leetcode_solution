// 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

// 示例：

// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        ListNode* tmp = NULL;
        while(l1 != NULL || l2 != NULL){
            int val1, val2;
            if(l1 != NULL){
                val1 = l1->val;
            }
            else{
                val1 = 0x7fffffff;
            }
            if(l2 != NULL){
                val2 = l2->val;
            }
            else{
                val2 = 0x7fffffff;
            }
            if(val1 > val2){
                if(ans == NULL){
                    ans = new ListNode(val2);
                    tmp = ans;
                }
                else{
                    auto ptr = new ListNode(val2);
                    tmp->next = ptr;
                    tmp = ptr;
                }
                l2 = l2->next;
            }
            else{
                if(ans == NULL){
                    ans = new ListNode(val1);
                    tmp = ans;
                }
                else{
                    auto ptr = new ListNode(val1);
                    tmp->next = ptr;
                    tmp = ptr;
                }
                l1 = l1->next;
            }
        }
        return ans;
    }
};