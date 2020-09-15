class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int max_k = -1, max_l = -1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                max_k = i;
            }
        }
        if(max_k == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[max_k] < nums[i]){
                max_l = i;
            }
        }
        swap(nums[max_l], nums[max_k]);
        int start = max_k+1; int end = nums.size()-1;
        while(start <= end){
            swap(nums[start++], nums[end--]);
        }
    }
};