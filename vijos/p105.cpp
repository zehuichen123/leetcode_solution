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
    vector<int>_preorder;
    vector<int>_inorder;
    int ptr_num = 0;
    TreeNode* construct(int start, int end){
        if(start > end || start >=_preorder.size()){
            return NULL;
        }
        int index = 0;
        for(index=start; index<end; index++){
            if(_preorder[ptr_num] == _inorder[index]){
                break;
            }
        }
        auto new_ptr = new TreeNode(_preorder[ptr_num]);
        ptr_num += 1;
        new_ptr->left = construct(start, index-1);
        new_ptr->right = construct(index+1, end);
        return new_ptr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        _preorder = preorder;
        _inorder = inorder;
        return construct(0, inorder.size());
    }
};