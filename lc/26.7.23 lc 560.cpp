



/*
leetcode 560    26.7.23
滑动窗口不可用 因为nums元素可能小于零 导致窗口滑动时可能会减小
前缀和记录 两个前缀和相减正好是区间和 每次mp++都更新了多的前缀和
只要sum-k的前缀和存在 说明sum-某一个前缀和等于k 满足题目要求 ans可以增加一
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())
            {
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};