class Solution {
public:
    double myPow(double x, int n) {
        double ptr;
        if(n < 0){
            ptr = 1. / double(x);
        }
        else{
            ptr = x;
        }
        double ans = 1;
        while(n != 0){
            if(n % 2 == 1 || n % 2 == -1){
                ans *= ptr;
            }
            ptr *= ptr;
            n /= 2;
        }
        return ans;
    }
};