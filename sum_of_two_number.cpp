// 两数之和

// 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

// 示例：

// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
// 输出：7 -> 0 -> 8
// 原因：342 + 465 = 807

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1, num2 , sum, tmp=0;
        struct ListNode* ans = NULL;
        struct ListNode* tmp_ptr;
        while(l1 != NULL || l2 != NULL){
            if(l1 != NULL){
                num1 = l1->val;
                l1 = l1->next;
            }
            else{
                num1 = 0;
            }
            if(l2 != NULL){
                num2 = l2->val;
                l2 = l2->next;
            }
            else{
                num2 = 0;
            }
            sum = num1 + num2 + tmp;
            tmp = sum / 10;
            if(ans == NULL){
                ans = new ListNode(sum % 10);
                tmp_ptr = ans;
            }
            else{
                auto tmp_ptr1 = new ListNode(sum % 10);
                tmp_ptr->next = tmp_ptr1;
                tmp_ptr = tmp_ptr1;
            }
        }
        if(tmp != 0){
            auto tmp_ptr1 = new ListNode(tmp);
            tmp_ptr->next = tmp_ptr1;
        }
        return ans;
    }
};