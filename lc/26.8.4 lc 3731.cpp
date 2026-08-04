



/*
leetcode 3731   26.8.4
排序+双指针 空缺元素入队
*/
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int pre = nums[0];
        for(auto t : nums)
        {
            if(t - pre > 1)
            {
                while(++pre != t)
                {
                    ans.push_back(pre);
                }
            }
            else pre = t;
        }
        return ans;
    }
};