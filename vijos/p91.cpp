class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size()+1, 0);
        if(s.size() == 0){
            return 0;
        }
        dp[0] = 1;
        if(s[0] != '0'){
            dp[1] = 1;
        }
        for(int i=1; i<s.size(); i++){
            if(s[i] != '0'){
                dp[i+1] += dp[i];
            }
            int tmp = (s[i-1] - '0') * 10 + s[i] - '0';
            if(tmp >= 10 && tmp <= 26){
                dp[i+1] += dp[i-1];
            }
        }
        return dp.back();
    }
};