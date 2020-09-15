class Solution {
public:
    int numSquares(int n) {
        int mid_n = sqrt(n);
        vector<int>dp(n+1, 0);
        for(int i=1; i<=n; i++){
            dp[i] = i;
        }
        for(int i=mid_n; i>=1; i--){
            for(int j=i*i; j<=n; j++){
                dp[j] = min(dp[j-i*i]+1, dp[j]);
            }
        }
        return dp.back();
    }
};