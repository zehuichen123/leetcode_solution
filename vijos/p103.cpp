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
    vector<vector<int>>ans;
    void visit(TreeNode* ptr, int level){
        if(ptr == NULL){
            return;
        }
        if(level == ans.size()){
            vector<int>_level = {};
            ans.push_back(_level);
        }
        ans[level].push_back(ptr->val);
        visit(ptr->left, level+1);
        visit(ptr->right, level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        visit(root, 0);
        for(int i=0; i<ans.size(); i++){
            if(i % 2 == 1){
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};