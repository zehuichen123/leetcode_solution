// Reverse Integer

// 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

// 示例 1:

// 输入: 123
// 输出: 321

// 示例 2:

// 输入: -123
// 输出: -321


#include<stack>
#include<climits>
class Solution {
public:
    int reverse(int x_) {
        int is_positive = 1;
        stack<int> rev_num;
        long long x = x_;
        if(x<0){
            is_positive = 0;
            x = -x;
        }
        while(x != 0){
            rev_num.push(x % 10);
            x /= 10;
        }
        long long ans = 0, bias = 1;
        while(!rev_num.empty()){
            ans += bias * rev_num.top();
            bias *= 10;
            rev_num.pop();
        }
        if(!is_positive){
            ans = -ans;
        }
        if(ans > INT_MAX or ans < INT_MIN){
            return 0;
        }
        else{
            return ans;
        }
    }
};