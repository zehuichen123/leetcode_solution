// 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.

// 示例 1:

// 输入:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 输出: [3, 14.5, 11]
// 解释:
// 第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
// 注意：

// 节点值的范围在32位有符号整数范围内。

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
    vector<double> ans;
    vector<int> count_num;
    void visit(TreeNode* ptr, int num){
        if(ptr==NULL){
            return;
        }
        if(ans.size()<=num){
            ans.push_back(ptr->val);
            count_num.push_back(1);
        }
        else{
            ans[num] += ptr->val;
            count_num[num] += 1;
        }
        visit(ptr->left, num + 1);
        visit(ptr->right, num + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        visit(root, 0);
        vector<double> res;
        for(int i=0;i<ans.size();i++){
            res.push_back(ans[i]/count_num[i]);
        }
        return res;
    }
};