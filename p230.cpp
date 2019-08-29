/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>_stack;
        int count = 0;
        auto ptr = root;
        while(!_stack.empty() || ptr != NULL){
            if(ptr != NULL){
                _stack.push(ptr);
                ptr = ptr->left;
            }
            else{
                ptr = _stack.top();
                _stack.pop();
                count += 1;
                if(count == k){
                    return ptr->val;
                }
                ptr = ptr->right;
            }
        }
        return -1;
    }
};