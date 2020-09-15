class Solution {
public:
    vector<vector<int>>ans;
    void findSolution(vector<int>solution, vector<bool>used, vector<int>nums){
        if(solution.size() == nums.size()){
            ans.push_back(solution);
            return;
        }
        for(int i=0; i<used.size(); i++){
            if(used[i] == false){
                used[i] = true;
                solution.push_back(nums[i]);
                findSolution(solution, used, nums);
                used[i] = false;
                solution.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>solution;
        vector<bool>used(nums.size(), false);
        findSolution(solution, used, nums);
        return ans;
    }
};