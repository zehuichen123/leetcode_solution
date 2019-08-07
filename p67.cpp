class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int len = a.size()>b.size()?a.size():b.size();
        bool hasNext = false;
        for(int i=0; i<len; i++){
            int a_num = 0;
            if(i < a.size()){
                a_num = a[a.size()-1-i] - '0';
            }
            int b_num = 0;
            if(i < b.size()){
                b_num = b[b.size()-1-i] - '0';
            }
            int sum = a_num + b_num + hasNext;
            hasNext = sum / 2;
            ans += (sum % 2) + '0';
        }
        if(hasNext){
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};