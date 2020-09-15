class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m-1, ptr = m + n - 1, ptr2 = n-1;
        while(ptr >= 0){
            int num1 = 0x80000000;
            if(ptr1>=0){
                num1 = nums1[ptr1];
            }
            int num2 = 0x80000000;
            if(ptr2>=0){
                num2 = nums2[ptr2];
            }
            if(num1 >= num2){
                nums1[ptr] = num1;
                ptr1 --;
            }
            else{
                nums1[ptr] = num2;
                ptr2 --;
            }
            ptr--;
        }
    }
};