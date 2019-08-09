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
    bool visit(TreeNode* node1, TreeNode* node2){
        if(node1 == NULL && node2 == NULL){
            return true;
        }
        else if(node1 != NULL && node2 != NULL && node1->val == node2->val){
            return visit(node1->left, node2->right) && visit(node1->right, node2->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return visit(root->right, root->left);
    }
};