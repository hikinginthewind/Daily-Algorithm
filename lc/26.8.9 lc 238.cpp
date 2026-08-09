



/*
leetcode 238    26.8.9
出现两个零可以直接输出零数组
出现一个零 在零位置输出纯净乘积
无零 直接用总乘积依次除以nums[i]
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long m = 1;
        int cnt = 0;
        long long pur = 1;
        for(int i = 0;i < n;i++)
        {
            if(nums[i] == 0) cnt++;
            else pur *= nums[i];
            m *= nums[i];
        }
        vector<int> ans(n,0);
        if(cnt >= 2) return ans;
        for(int i = 0;i < n;i++)
        {
            if(nums[i] != 0) ans[i] = m / nums[i];
            else ans[i] = pur;
        }
        return ans;
    }
};