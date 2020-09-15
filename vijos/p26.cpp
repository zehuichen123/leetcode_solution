class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int prev_num = nums[0];
        int count = 0;
        nums[count] = prev_num;
        count += 1;
        for(int i=0; i<nums.size(); i++){
            if(prev_num == nums[i]){
                continue;
            }
            else{
                nums[count] = nums[i];
                count += 1;
                prev_num = nums[i];
            }
        }
        return count;
    }
};