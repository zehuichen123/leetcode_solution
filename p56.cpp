class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        for(int i=0; i<intervals.size(); i++){
            if(i == 0){
                ans.push_back(intervals[0]);
            }
            else{
                vector<int>curr = intervals[i];
                vector<int>last = ans.back();
                if(last[1] >= curr[0]){
                    ans[ans.size()-1][1] = max(curr[1], last[1]);
                }
                else{
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
};