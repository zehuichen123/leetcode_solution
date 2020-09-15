// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

// 示例 1：

// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。
// 示例 2：

// 输入: "cbbd"
// 输出: "bb"


class Solution {
public:
    int arr[1001][1001];
    string longestPalindrome(string s) {
        int max_len = 0, left_index = 0, right_index=0;
        for(int i=0;i<s.length();i++){
            arr[i][i] = 1;
            if(arr[i][i] > max_len){
                max_len = arr[i][i];
                left_index = i;
                right_index = i;
            }
        }
        for(int i=0;i<s.length();i++){
            if(s[i] == s[i+1]){
                arr[i][i+1] = 2;
                if(arr[i][i+1] > max_len){
                    max_len = arr[i][i+1];
                    left_index = i;
                    right_index = i+1;
                }
            }
        }
        for(int j=2;j<s.length();j++){
            for(int i=0;i<j;i++){
                if(s[i] == s[j] and arr[i+1][j-1] != 0){
                    arr[i][j] = arr[i+1][j-1] + 2;
                    if(arr[i][j] > max_len){
                        max_len = arr[i][j];
                        left_index = i;
                        right_index = j;
                    }
                }
            }
        }
        return s.substr(left_index, right_index-left_index + 1);
    }
};