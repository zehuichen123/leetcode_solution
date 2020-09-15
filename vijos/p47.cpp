class Solution {
public:
    vector<vector<int>>ans;
    void findSolution(vector<int>solution, vector<bool>used, vector<int> nums){
        if(solution.size() == nums.size()){
            ans.push_back(solution);
            return;
        }
        for(int i=0; i<used.size(); i++){
            if(used[i] == false){
                if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false){
                    continue;
                }
                solution.push_back(nums[i]);
                used[i] = true;
                findSolution(solution, used, nums);
                solution.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>solution;
        vector<bool>used(nums.size(), false);
        sort(nums.begin(), nums.end());
        findSolution(solution, used, nums);
        return ans;
    }
};