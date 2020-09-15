class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev = 0x7fffffff;
        int ans = 0;
        for(int i=1; i<prices.size(); i++){
            prev = min(prev, prices[i-1]);
            ans = max(prices[i] - prev, ans);
        }
        return ans;
    }
};