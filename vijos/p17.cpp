// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



// Example:

// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

class Solution {
public:
    vector<string> num2word = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> solutions = {""};
    void match(char letter){
        int num = letter - '0';
        vector<string> tmp_solutions = {};
        for(auto res1: solutions){
            for(auto res2:num2word[num - 2]){
                tmp_solutions.push_back(res1+res2);
            }
        }
        solutions = tmp_solutions;
    }
    vector<string> letterCombinations(string digits) {
        for(auto letter:digits){
            match(letter);
        }
        if(digits == ""){
            solutions = vector<string>{};
        }
        return solutions;
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>>dp ={{""}};
        for(int i=1; i<=n; i++){
            vector<string>_dp = {};
            for(int j=0; j<i; j++){
                int tmp1 = j;
                int tmp2 = i-j-1;
                for(int m=0; m<dp[tmp1].size(); m++){
                    for(int n=0; n<dp[tmp2].size(); n++){
                        string ans = "";
                        ans += ('('+dp[tmp1][m]+')'+dp[tmp2][n]);
                        _dp.push_back(ans);
                    }
                }
            }
            dp.push_back(_dp);
        }
        return dp[n];
    }
};