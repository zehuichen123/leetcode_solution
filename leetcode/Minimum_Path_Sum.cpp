// 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

// 说明：每次只能向下或者向右移动一步。

// 示例:

// 输入:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// 输出: 7
// 解释: 因为路径 1→3→1→1→1 的总和最小。

class Solution {
public:
    int dp[1000][1000];
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        dp[0][0] = grid[0][0];
        for(int i=1; i<width; i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        for(int i=1; i<height; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for(int i=1; i<height; i++){
            for(int j=1; j<width; j++){
                int tmp = dp[i-1][j]>dp[i][j-1]?dp[i][j-1]:dp[i-1][j];
                dp[i][j] = tmp + grid[i][j];
            }
        }
        return dp[height-1][width-1];
    }
};
