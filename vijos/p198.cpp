class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+2);
        for(int i=0; i<nums.size(); i++){
            dp[i+2] = max(dp[i+1], dp[i] + nums[i]);
        }
        return dp.back();
    }
};