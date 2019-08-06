class Solution {
public:
    vector<vector<int>> ans={};
    void findSolution(vector<int>&nums, int target, int ptr, vector<int>solution, int sum){
        if(sum > target){
           return;
        }
        else if(sum == target){
            ans.push_back(solution);
            return;
        }
        for(int i=ptr; i<nums.size(); i++){
            solution.push_back(nums[i]);
            findSolution(nums, target, i, solution, sum+nums[i]);
            solution.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>solution;
        findSolution(candidates, target, 0, solution, 0);
        return ans;
    }
};