class Solution {
public:
    int dp[1000][1000];
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        for(int i=0; i<=len1; i++){
            dp[0][i] = i;
        }
        for(int i=0; i<=len2; i++){
            dp[i][0] = i;
        }
        for(int i=1; i<=len2; i++){
            for(int j=1; j<=len1; j++){
                if(word1[j-1] == word2[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int tmp = dp[i-1][j]>dp[i][j-1]?dp[i][j-1]:dp[i-1][j];
                    dp[i][j] = dp[i-1][j-1]>tmp?tmp:dp[i-1][j-1];
                    dp[i][j] += 1;
                }
            }
        }
        // for(int i=0;i<=len2;i++){
        //     for(int j=0;j<=len1;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        return dp[len2][len1];
    }
};
