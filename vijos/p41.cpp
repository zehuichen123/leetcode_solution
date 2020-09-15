class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len_size = nums.size();
        vector<int> tmp(len_size+1);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0 && nums[i] < nums.size()+1){
                tmp[nums[i]-1] = nums[i];
            }
        }
        for(int i=0; i<tmp.size(); i++){
            if(tmp[i] == 0){
                return i+1;
            }
        }
        return 1;
    }
};