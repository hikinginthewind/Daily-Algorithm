



/*
leetcode 2996   26.8.11
是昨天做的hot100的衍生版本
答案范围在sum到sum+n内 a数组记录nums中有的衍射 找到第一个没出现的最小值
*/
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();
        int poi = 0;
        for(int i = 1;i < n;i++)
        {
            if(nums[i] == nums[i - 1] + 1)
            {    
                sum += nums[i];
                poi = i;
            }
            else break;
        }
        vector<int> a(n + 1,0);
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;i++)
        {
            if(nums[i] >= sum && nums[i] < sum + n)
                a[nums[i] - sum]++;
        }
        for(int i = 0;i <= n;i++)
        {
            if(a[i] == 0)
            {
                sum = sum + i;
                break;
            }
        }
        return sum;
    }
};