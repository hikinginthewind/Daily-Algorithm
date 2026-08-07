



/*
leetcode 56     26.8.7
明天补题
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i = 1;i < n;i++)
        {
            int l = intervals[i][0];
            int r = intervals[i][1];
            if(l == intervals[i - 1][0]) continue;
            else ans.push_back(intervals[i - 1]);
        }
        vector<vector<int>> res;
        re
        for(auto t : ans)
    }
};