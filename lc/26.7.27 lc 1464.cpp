



/*
leetcode 1464   26.7.27
数组--后排序 看头尾两个相乘
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            nums[i]--;
        }
        sort(nums.begin(),nums.end());
        int ans = nums[n - 1] * nums[n - 2];
        ans = max(ans,nums[0] * nums[1]);
        return ans;
    }
};