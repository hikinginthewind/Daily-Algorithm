



/*
leetcode 3718   26.8.25
哈希表
*/
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt[105] = {0};
        int n = nums.size();
        for(int i = 0;i < n;i++) cnt[nums[i]] ++;
        int num;
        for(int i = 1;i * k <= 200;i++)
        {
            if(i * k > 100) return i * k;
            if(cnt[i * k] == 0)
            {
                num = i;
                break;
            }
        }
        return num * k;
    }
};