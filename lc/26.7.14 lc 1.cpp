



/*
leetcode 1  2026.7.14
哈希表 + 双指针
今天改下 从hot100开始刷 不然有的每日一题超纲得很
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numsSize = nums.size();
        vector<vector<int>> g(numsSize,vector<int>(2));
        vector<int> ans;
        for(int i = 0;i < numsSize;i++)
        {
            g[i][0] = nums[i];
            g[i][1] = i;
        }
        sort(g.begin(),g.end());
        int l = 0,r = numsSize - 1;
        while(l < r)
        {
            if(g[l][0] + g[r][0] == target)
            {
                ans.push_back(g[l][1]);
                ans.push_back(g[r][1]);
                break;
            }
            else if(g[l][0] + g[r][0] > target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return ans;
        }
};