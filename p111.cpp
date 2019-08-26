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
    int min_depth = 0x7fffffff;
    void visit(TreeNode* ptr, int level){
        if(ptr == NULL){
            return;
        }
        if(ptr->left == NULL && ptr->right == NULL){
            min_depth = min(min_depth, level);
        }
        else{
            visit(ptr->right, level+1);
            visit(ptr->left, level+1);
        }
    }
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        visit(root, 1);
        return min_depth;
    }
};