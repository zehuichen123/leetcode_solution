class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n, vector<int>(n, 0));
        int count=0, sum_all=n * n, ptr1=0, ptr2=-1, time=0;
        while(count < sum_all){
            while(ptr2+1 < n-time){
                ans[ptr1][++ptr2] = ++count;
            }
            while(ptr1+1 < n-time){
                ans[++ptr1][ptr2] = ++count;
            }
            while(ptr2-1 > -1+time){
                ans[ptr1][--ptr2] = ++count;
            }
            while(ptr1-1 > 0+time){
                ans[--ptr1][ptr2] = ++count;
            }
            time += 1;
        }
        return ans;
    }
};