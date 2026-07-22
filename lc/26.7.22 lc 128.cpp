



/*
leetcode 128    26.7.21(7.22补)
哈希表unordered_set(集合) -->存在与否
每次从队列头开始查找 y保持向前一步查找 y-x即为长度
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans = 0;
        for(int x : s)
        {
            if(!s.count(x - 1))
            {
                int y = x + 1;
                while(s.count(y))
                {
                    y++;
                }
                ans = max(ans,y - x);
            }
        }
        return ans;
    }
};