



/*
leetcode 1288   2026.7.6
先对区间排序
按顺序遍历
下限值相等的区间看上限值 上限大的包含上限小的
上限值不相等 下限值更大的包含更小的
每次把被包含的区间改成包含区间
*/
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = n;
        sort(intervals.begin(),intervals.end());
        for(int i = 0;i < n - 1;i++)
        {
            if(intervals[i][0] == intervals[i + 1][0])
            {
                if(intervals[i][1] <= intervals[i + 1][1])
                {
                    ans--;
                    intervals[i][1] = intervals[i + 1][1];
                }
            }
            else
            {
                if(intervals[i][1] >= intervals[i + 1][1])
                {
                    ans--;
                    intervals[i + 1][0] = intervals[i][0];
                    intervals[i + 1][1] = intervals[i][1];
                }
            }
        }
        return ans;
    }
};