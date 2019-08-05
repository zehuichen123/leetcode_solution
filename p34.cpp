class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return vector<int>{-1, -1};
        }
        int start = 0, end = nums.size()-1;
        int best_left = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] > target){
                end = mid - 1;
            }
            else if(nums[mid] == target){
                best_left = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        if(best_left == -1){
            return vector<int>{-1, -1};
        }
        start = 0; end = nums.size()-1;
        int best_right = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] > target){
                end = mid - 1;
            }
            else if(nums[mid] == target){
                best_right = mid;
                start = mid + 1;
            }
            else{
                start = mid + 1;
            }
        }
        return vector<int>{best_left, best_right};
    }
};