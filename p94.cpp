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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>_stack;
        vector<int>ans;
        auto ptr = root;
        while(!_stack.empty() || ptr != NULL){
            if(ptr != NULL){
                _stack.push(ptr);
                ptr = ptr->left;
            }
            else{
                ptr = _stack.top();
                _stack.pop();
                ans.push_back(ptr->val);
                ptr = ptr->right;
            }
        }
        return ans;
    }
};