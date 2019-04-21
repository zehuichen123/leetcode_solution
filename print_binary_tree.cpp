// 在一个 m*n 的二维字符串数组中输出二叉树，并遵守以下规则：

// 行数 m 应当等于给定二叉树的高度。
// 列数 n 应当总是奇数。
// 根节点的值（以字符串格式给出）应当放在可放置的第一行正中间。根节点所在的行与列会将剩余空间划分为两部分（左下部分和右下部分）。你应该将左子树输出在左下部分，右子树输出在右下部分。左下和右下部分应当有相同的大小。即使一个子树为空而另一个非空，你不需要为空的子树输出任何东西，但仍需要为另一个子树留出足够的空间。然而，如果两个子树都为空则不需要为它们留出任何空间。
// 每个未使用的空间应包含一个空的字符串""。
// 使用相同的规则输出子树。
// 示例 1:

// 输入:
//      1
//     /
//    2
// 输出:
// [["", "1", ""],
//  ["2", "", ""]]
// 示例 2:

// 输入:
//      1
//     / \
//    2   3
//     \
//      4
// 输出:
// [["", "", "", "1", "", "", ""],
//  ["", "2", "", "", "", "3", ""],
//  ["", "", "4", "", "", "", ""]]
// 示例 3:

// 输入:
//       1
//      / \
//     2   5
//    / 
//   3 
//  / 
// 4 
// 输出:
// [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
//  ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
//  ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
//  ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
// 注意: 二叉树的高度在范围 [1, 10] 中。

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
    int m;
    int find_height(TreeNode* ptr, int num){
        if(ptr == NULL){
            return num-1;
        }
        int height1 = find_height(ptr->left, num+1);
        int height2 = find_height(ptr->right, num+1);
        if(height1 > height2){
            return height1;
        }
        else{
            return height2;
        }
    }
    void write(TreeNode* ptr, vector<vector<string>>& ans, int row, int col){
        if(ptr == NULL){
            return;
        }
        write(ptr->left, ans, row+1, col-pow(2, m-row-2));
        //cout<<"visit"<<row<<' '<<col<<endl;
        ans[row][col] = to_string(ptr->val);
        write(ptr->right, ans, row+1, col+pow(2, m-row-2));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        m = find_height(root, 1);
        int n = pow(2, m) - 1;
        //cout<<m<<" "<<n<<endl;
        vector<vector<string>> ans;
        for(int i=0;i<m;i++){
            vector<string> level;
            for(int j=0;j<n;j++){
                level.push_back("");
            }
            ans.push_back(level);
        }
        write(root, ans, 0, pow(2, m-1)-1);
        return ans;
    }
};