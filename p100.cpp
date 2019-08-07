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
        else if(node1 && node2 && node1->val == node2->val){
            return visit(node1->left, node2->left) && visit(node1->right, node2->right);
        }
        else{
            return false;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return visit(p, q);
    }
};