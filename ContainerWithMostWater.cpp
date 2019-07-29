// 盛最多水的容器

// 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
// 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

// 说明：你不能倾斜容器，且 n 的值至少为 2。


class Solution {
public:
    int maxArea(vector<int>& height) {
        int ptr1 = 0, ptr2 = height.size()-1;
        int ans = 0;
        while(ptr1 <= ptr2){
            if(height[ptr1] < height[ptr2]){
                int area = height[ptr1] * (ptr2 - ptr1);
                if(ans < area){
                    ans = area;
                }
                ptr1 += 1;
            }
            else{
                int area = height[ptr2] * (ptr2 - ptr1);
                if(ans < area){
                    ans = area;
                }
                ptr2 -= 1;
            }
        }
        return ans;
    }
};