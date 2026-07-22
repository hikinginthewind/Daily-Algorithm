



/*
leetcode 42 26.7.22
比较有难度的双指针
两边都找最大值 可以找到当前的第二大值 第二大值到第一大值中间显然有水坑
maxl - height[left]可以得到当前 left 下缀的水坑深度
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxl = 0,maxr = 0;
        int left = 0;
        int right = n - 1;
        int ans = 0;
        while(left < right)
        {
            maxl = max(maxl,height[left]);
            maxr = max(maxr,height[right]);
            if(maxl < maxr)
            {
                ans += maxl - height[left];
                left++;
            }
            else
            {
                ans += maxr - height[right];
                right--;
            }
        }
        return ans;
    }
};