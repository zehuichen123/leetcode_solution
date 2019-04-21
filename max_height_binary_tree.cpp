// 给定一个二叉树，找出其最大深度。

// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

// 说明: 叶子节点是指没有子节点的节点。

// 示例：
// 给定二叉树 [3,9,20,null,null,15,7]，

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回它的最大深度 3 。

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
    int find(TreeNode* ptr, int num){
        if(ptr == NULL){
            return num - 1;
        }
        int height1 = find(ptr->left, num + 1);
        int height2 = find(ptr->right, num + 1);
        if(height1<height2){
            return height2;
        }
        else{
            return height1;
        }
    }
    int maxDepth(TreeNode* root) {
        return find(root, 1);
    }
};