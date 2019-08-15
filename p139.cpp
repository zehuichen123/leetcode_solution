class Solution {
public:
    bool compare(string s, int start, string p){
        if(p.size() + start > s.size()){
            return false;
        }
        for(int i=0; i<p.size(); i++){
            if(s[i+start] != p[i]){
                return false;
            }
        }
        return true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1);
        dp[0] = 1;
        for(int i=0; i<s.size(); i++){
            for(auto str: wordDict){
                if(i+1 - int(str.size())>=0 && dp[i+1 - str.size()]){
                    if(compare(s, i+1-str.size(), str)){
                        dp[i+1] = 1;
                        break;
                    }
                }
            }
        }
        return dp.back();
    }
};