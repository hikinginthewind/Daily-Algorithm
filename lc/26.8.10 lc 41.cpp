



/*
leetcode 41     26.8.10
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n + 1,0);
        int ans;
        for(int i = 0;i < n;i++)
            if(nums[i] > 0 && nums[i] <= n)
                a[nums[i] - 1]++;
        for(int i = 0;i <= n;i++)
            if(a[i] == 0)
            {
                ans = i + 1;
                break;
            }
        return ans;
    }
};