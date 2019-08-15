class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        int height = matrix.size(), width = matrix[0].size();
        vector<vector<int>>dp(height, vector<int>(width, 0));
        dp[0][0] = matrix[0][0] - '0';
        int ans = dp[0][0];
        for(int i=1; i<width; i++){
            dp[0][i] = matrix[0][i] - '0';
            ans = max(ans, dp[0][i]);
        }
        for(int i=1; i<height; i++){
            dp[i][0] = matrix[i][0] - '0';
            ans = max(ans, dp[i][0]);
        }
        ans = min(ans, 1);
        for(int i=1; i<height; i++){
            for(int j=1; j<width; j++){
                dp[i][j] = (matrix[i][j] - '0') * (min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1);
                ans = max(dp[i][j], ans);
            }
        }
        return ans * ans;
    }
};