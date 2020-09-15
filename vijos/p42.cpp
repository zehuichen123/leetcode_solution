class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>max_left={0};
        vector<int>max_right={0};
        int count = 0;
        if(height.size() == 0){
            return 0;
        }
        for(int i=1; i<height.size()-1; i++){
            max_left.push_back(max(max_left[i-1], height[i-1]));
        }
        for(int i=height.size()-2; i>0; i--){
            max_right.push_back(max(max_right[height.size()-i-2], height[i+1]));
        }
        max_right.push_back(0);
        reverse(max_right.begin(), max_right.end());
        for(int i=1; i<height.size()-1; i++){
            int max_height = min(max_right[i], max_left[i]);
            count += max(max_height - height[i], 0);
        }
        return count;
    }
};