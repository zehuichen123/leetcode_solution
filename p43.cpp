class Solution {
public:
    string multiply(string num1, string num2) {
        int max_len = num1.size()+num2.size();
        vector<int> res(max_len);
        string ans = "";
        if(num1 == "0" && num2 == "0"){
            return "0";
        }
        for(int i=0; i<num2.size(); i++){
            for(int j=0; j<num1.size(); j++){
                int tmp = (num2[num2.size()-i-1] - '0') * (num1[num1.size()-j-1] - '0');
                res[i+j] += tmp % 10;
                res[i+j+1] += tmp / 10;
            }
        }
        for(int i=0; i<max_len-1; i++){
            res[i+1] += res[i] / 10;
            res[i] %= 10;
        }
        int ptr = max_len-1;
        while(res[ptr] == 0 && ptr>0){ptr--;}
        for(int i=ptr; i>=0; i--){
            ans += (res[i]+'0');
        }
        return ans;
    }
};