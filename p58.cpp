class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size()-1;
        int start = len;
        while(s[len] == ' ' && len >= 0){
            len--;
        }
        start = len;
        while(s[len] != ' ' && len >= 0){
            len--;
        }
        return start - len;
    }
};