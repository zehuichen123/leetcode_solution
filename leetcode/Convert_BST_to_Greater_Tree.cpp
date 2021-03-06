// 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，
// 使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

// 例如：

// 输入: 二叉搜索树:
//               5
//             /   \
//            2     13

// 输出: 转换为累加树:
//              18
//             /   \
//           20     13


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
    int sum = 0;
    void visit(TreeNode* node){
        if(node == NULL){
            return;
        }
        else{
            visit(node->right);
            int tmp = node->val;
            node->val += sum;
            sum += tmp;
            visit(node->left);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        visit(root);
        return root;
    }
};