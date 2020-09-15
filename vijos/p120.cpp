class Solution {
public:
    vector<vector<int>>dp={1, vector<int>(1, 0)};
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=1; i<=triangle.size(); i++){
            vector<int>_dp;
            for(int j=0; j<triangle[i-1].size(); j++){
                if(j == 0){
                    _dp.push_back(dp[i-1][j] + triangle[i-1][j]);
                }
                else if(j == triangle[i-1].size()-1){
                    _dp.push_back(dp[i-1][j-1] + triangle[i-1][j]);
                }
                else{
                    _dp.push_back(min(dp[i-1][j], dp[i-1][j-1]) + triangle[i-1][j]);
                }
            }
            dp.push_back(_dp);
        }
        int ans = 0x7fffffff;
        for(auto i:dp.back()){
            if(ans > i){
                ans = i;
            }
        }
        return ans;
    }
};