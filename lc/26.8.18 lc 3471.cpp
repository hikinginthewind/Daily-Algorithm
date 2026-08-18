



/*
leetcode 3471   26.8.18
标个简单真给我唬住了 一看通过率30%
把所有特殊情况单独分出来解决就行了 还是有点麻烦的
*/
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;
        int ans = INT_MIN;
        if(k == 1)
        {
            bool p = false;
            unordered_map<int,int> cnt;
            for(int i = 0;i < n;i++)
            {
                cnt[nums[i]]++;
            }
            for(auto t : cnt)
            {
                if(t.second == 1)
                {
                    ans = max(ans,t.first);
                    p = true;
                }
            }
            if(p) return ans;
            else return -1;
        }
        int len = n - k;
        if(len == 0)
        {
            for(int i = 0;i < n;i++) ans = max(ans,nums[i]);
        }
        else
        {
            int head = nums[0];
            int down = nums[n - 1];
            bool p1 = false;
            bool p2 = false;
            for(int i = 0;i < n;i++)
            {
                if(i != 0 && nums[i] == head) p1 = true;
                if(i != n - 1 && nums[i] == down) p2 = true;
                if(p1 && p2) break;
            }
            if(p1 && p2) return -1;
            else if(p1) ans = nums[n - 1];
            else if(p2) ans = nums[0];
            else ans = max(nums[0],nums[n - 1]);
        }
        return ans;
    }
};