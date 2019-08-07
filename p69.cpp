class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x;
        while(r >= l){
            long long mid = (r + l) / 2;
            long long prod = mid * mid;
            if(prod > x){
                r = mid - 1;
            }
            else if(prod < x){
                l = mid + 1;
            }
            else{
                return mid;
            }
        }
        if(l * l > x){
            return l-1;
        }
        else{
            return l;
        }
    }
};