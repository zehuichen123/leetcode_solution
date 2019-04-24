 // Sum Closest

// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

// 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

// 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

 #include<algorithm>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0x7fffffff, sum;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int j = i+1, l = nums.size() - 1;
            while(j < l){
                int three_sum = nums[i] + nums[j] + nums[l];
                if(abs(three_sum - target) < ans){
                    ans = abs(three_sum - target);
                    sum = three_sum;
                }
                if (three_sum == target){
                    return target;
                }
                else if(three_sum < target){
                    j += 1;
                }
                else{
                    l -= 1;
                }
            }
        }
        return sum;
    }
};