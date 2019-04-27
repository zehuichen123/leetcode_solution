// 1. Confusing Number
// Given a number N, return true if and only if it is a confusing number, which satisfies the following condition:

// We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid. A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.

 

// Example 1:



// Input: 6
// Output: true
// Explanation: 
// We get 9 after rotating 6, 9 is a valid number and 9!=6.
// Example 2:



// Input: 89
// Output: true
// Explanation: 
// We get 68 after rotating 89, 86 is a valid number and 86!=89.
// Example 3:



// Input: 11
// Output: false
// Explanation: 
// We get 11 after rotating 11, 11 is a valid number but the value remains the same, thus 11 is not a confusing number.


class Solution {
public:
    bool confusingNumber(int N) {
        vector<int>check = {0, 1, 6, 8, 9};
        vector<int>nums = {};
        do{
            int num = N % 10;
            N /= 10;
            bool label = false;
            nums.push_back(num);
            for(auto ptr: check){
                if(ptr == num){
                    label = true;
                    break;
                }
            }
            if(label==false){
                return false;
            }
        }while(N);
        bool pass = true;
        for(int i=0;i<=nums.size()/2; i++){
            if(nums[i] == 0||nums[i] == 1||nums[i] == 8){
                if(nums[i] != nums[nums.size() - 1 - i]){
                    pass = false;
                }
            }
            else{
                if(nums[i] + nums[nums.size() -1 - i] != 15){
                    pass = false;
                }
            }
        }
        if(pass){
            return false;
        }
        return true;
    }
};