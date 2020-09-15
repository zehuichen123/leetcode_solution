class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans={};
        if(matrix.size() == 0){
            return ans;
        }
        vector<vector<bool>>used(matrix.size(), vector<bool>(matrix[0].size(), false));
        int height=matrix.size(), width=matrix[0].size();
        int ptr1=0, ptr2=-1, nums=height * width, count=0, direction=0;
        while(count<nums){
            if(direction == 0){
                if(ptr2 + 1 < width && used[ptr1][ptr2 + 1] == false){
                    ans.push_back(matrix[ptr1][ptr2+1]);
                    used[ptr1][ptr2+1] = true;
                    ptr2 += 1;
                    count += 1;
                }
                else{
                    direction += 1;
                }
            }
            else if(direction == 1){
                if(ptr1 + 1 < height && used[ptr1+1][ptr2] == false){
                    ans.push_back(matrix[ptr1+1][ptr2]);
                    used[ptr1+1][ptr2] = true;
                    ptr1 += 1;
                    count += 1;
                }
                else{
                    direction += 1;
                }
            }
            else if(direction == 2){
                if(ptr2 - 1 >= 0 && used[ptr1][ptr2-1] == false){
                    ans.push_back(matrix[ptr1][ptr2-1]);
                    used[ptr1][ptr2-1] = true;
                    ptr2 -= 1;
                    count += 1;
                }
                else{
                    direction += 1;
                }
            }
            else{
                if(ptr1 - 1 >= 0 && used[ptr1-1][ptr2] == false){
                    ans.push_back(matrix[ptr1-1][ptr2]);
                    used[ptr1-1][ptr2] = true;
                    ptr1 -= 1;
                    count += 1;
                }
                else{
                    direction = 0;
                }
            }
        }
        return ans;
    }
};