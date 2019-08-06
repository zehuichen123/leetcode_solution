class Solution {
public:
    vector<vector<int>> ans={};
    void findSolution(vector<int>&nums, int target, int ptr, vector<int>solution, int sum){
        if(sum == target){
            ans.push_back(solution);
            return;
        }
        for(int i=ptr; i<nums.size(); i++){
            if(i > ptr && nums[i] == nums[i-1]){
                continue;
            }
            else{
                solution.push_back(nums[i]);
                if(sum+nums[i] > target){
                    break;
                }
                findSolution(nums, target, i+1, solution, sum+nums[i]);
                solution.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<int>solution = {};
        findSolution(candidates, target, 0, solution, 0);
        return ans;
    }
};