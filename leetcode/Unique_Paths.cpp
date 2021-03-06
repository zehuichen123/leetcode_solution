// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

// 问总共有多少条不同的路径？



// 例如，上图是一个7 x 3 的网格。有多少可能的路径？

// 说明：m 和 n 的值均不超过 100。

// 示例 1:

// 输入: m = 3, n = 2
// 输出: 3
// 解释:
// 从左上角开始，总共有 3 条路径可以到达右下角。
// 1. 向右 -> 向右 -> 向下
// 2. 向右 -> 向下 -> 向右
// 3. 向下 -> 向右 -> 向右
// 示例 2:

// 输入: m = 7, n = 3
// 输出: 28



class Solution {
public:
    int dp[100][100];
    int uniquePaths(int m, int n) {
        dp[0][0] = 1;
        for(int i=1;i<n;i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<m; i++){
            dp[0][i] = 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j][i] = dp[j-1][i] + dp[j][i-1];
            }
        }
        return dp[n-1][m-1];
        // long long max = 1;
        // n -= 1;
        // m -= 1;
        // int big = m > n? m: n;
        // int small = m < n? m: n;
        // if(small == 0){
        //     return 1;
        // }
        // for(int i=0; i<small; i++){
        //     max *= (small + big - i);
        //     max /= (i + 1);
        // }
        // return max;
    }
};