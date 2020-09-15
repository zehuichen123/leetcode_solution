class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0; i+needle.size()<haystack.size()+1; i++){
            bool isFind = true;
            for(int j=0; j<needle.size(); j++){
                if(haystack[i+j] == needle[j]){
                    continue;
                }
                else{
                    isFind = false;
                    break;
                }
            }
            if(isFind){
                return i;
            }
        }
        return -1;
    }
};