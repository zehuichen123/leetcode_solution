class Solution {
public:
    bool canJump(vector<int>& nums) {
        int min_num = nums.size() -1, ptr=nums.size()-1;
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i] + i >= min_num){
                min_num = i;
            }
        }
        if(nums[0] >= min_num){
            return true;
        }
        else{
            return false;
        }
    }
};