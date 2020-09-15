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
    vector<TreeNode*>visit(int start, int end){
        vector<TreeNode*>ans;
        if(start > end){
            TreeNode* empty_ptr = NULL;
            ans.push_back(empty_ptr);
            return ans;
        }
        for(int i=start; i<=end; i++){
            for(TreeNode* left: visit(start, i-1)){
                for(TreeNode* right: visit(i+1, end)){
                    auto head = new TreeNode(i);
                    head->left = left;
                    head->right = right;
                    ans.push_back(head);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            vector<TreeNode*>ans;
            return ans;
        }
        return visit(1, n);
    }
};