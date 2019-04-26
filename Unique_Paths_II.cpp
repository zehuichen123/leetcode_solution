// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？



// 网格中的障碍物和空位置分别用 1 和 0 来表示。

// 说明：m 和 n 的值均不超过 100。

// 示例 1:

// 输入:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// 输出: 2
// 解释:
// 3x3 网格的正中间有一个障碍物。
// 从左上角到右下角一共有 2 条不同的路径：
// 1. 向右 -> 向右 -> 向下 -> 向下
// 2. 向下 -> 向下 -> 向右 -> 向右


class Solution {
public:
    long long dp[100][100];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        bool h_stop = true, w_stop= true;
        for(int i = 0; i< width; i++){
            if(obstacleGrid[0][i] != 1 && w_stop){
                dp[0][i] = 1;
            }
            else{
                dp[0][i] = 0;
                w_stop = false;
            }
        }
        for(int j = 0; j< height; j++){
            if(obstacleGrid[j][0] != 1 && h_stop){
                dp[j][0] = 1;
            }
            else{
                dp[j][0] = 0;
                h_stop = false;
            }
        }
        for(int j=1; j<height; j++){
            for(int i=1; i< width; i++){
                if(obstacleGrid[j][i] != 1){
                    dp[j][i] = dp[j-1][i] + dp[j][i-1];
                }
                else{
                    dp[j][i] = 0;
                }
            }
        }
        return dp[height-1][width-1];
    }
};