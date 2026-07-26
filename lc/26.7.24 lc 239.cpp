



/*
leetcode 239    26.7.24
滑动窗口维护最大值 暴力会爆时间
简单滑动窗口在最大值移出窗口时无法记忆第二大值 使用一个deque来不断更新读入新nums时的当前最大值
、每次deque留下新窗口的最大值下标
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i = 0;i < n;i++)
        {
            while(!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front() <= i - k) dq.pop_front();
            if(i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
