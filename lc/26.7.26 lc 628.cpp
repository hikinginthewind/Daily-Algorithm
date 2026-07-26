



/*
leetcode 628    26.7.26
一开始没注意 nums 可能小于零
那就多加几个正负的判断
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[n - 1] * nums[n - 2] * nums[n - 3];
        if(ans > 0) ans = max(ans,nums[0] * nums[1] * nums[n - 1]);
        else
        {
            if(nums[n - 1] > 0) ans = max(ans,nums[0] * nums[1] * nums[n - 1]);
            else ans = max(ans,nums[0] * nums[1] * nums[2]);
        }
        return ans;
    }
};