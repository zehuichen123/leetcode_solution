// 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

// 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

#include<algorithm>
class Solution {
public:
    bool find(int target, vector<int>& nums){
        int start = 0, end = nums.size() - 1;
        int mid = (start + end) / 2;
        if(nums[mid] == target){
            return true;
        }
        else if(nums[mid] < target){
            auto temp = vector<int>(nums.begin()+mid+1, nums.end());
            if(temp.size() == 0){
                return false;
            }
            return find(target, temp);
        }
        else{
            auto tmp = vector<int>(nums.begin(), nums.begin()+mid);
            if(tmp.size() == 0){
                return false;
            }
            return find(target, tmp);
        }
    }
    int move_ptr1(int ptr1, vector<int>& nums){
        while(ptr1 < nums.size() - 2){
            ptr1 += 1;
            if (nums[ptr1] == nums[ptr1-1]){
                continue;
            }
            else{
                break;
            }
        }
        return ptr1;
    }
    int move_ptr2(int ptr2, vector<int>& nums){
        while(ptr2 < nums.size() - 1){
            ptr2 += 1;
            if (nums[ptr2] == nums[ptr2-1]){
                continue;
            }
            else{
                break;
            }
        }
        return ptr2;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<2){
            return ans;
        }
        sort(nums.begin(), nums.end());
        int ptr1=0, ptr2= 1;
        while(ptr1 < nums.size()-2){
            while(ptr2 < nums.size()-1){
                int sum = nums[ptr1] + nums[ptr2];
                auto tmp = vector<int>(nums.begin()+ptr2+1, nums.end());
                if(tmp.size() != 0){
                    if(find(-sum, tmp)){
                        vector<int> solution = {nums[ptr1], nums[ptr2], -sum};
                        ans.push_back(solution);
                    }
                }
                ptr2 = move_ptr2(ptr2, nums);
            }
            ptr1 = move_ptr1(ptr1, nums);
            ptr2 = ptr1 + 1;
        }
        return ans;
    }
};