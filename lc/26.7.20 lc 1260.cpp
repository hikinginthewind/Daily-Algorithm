



/*
leetcode 1260   26.7.20
用同余在数组里绕环
nx = newidx / m 是因为 nx 范围 0--m-1 天生向下取整
*/
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int all = n * m;
        k %= all;
        if(k == 0) return grid;
        
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                int idx = i * m + j;
                int newidx = (idx + k) %  all;
                int nx = newidx / m;
                int ny = newidx % m;
                ans[nx][ny] = grid[i][j];
            }
        }
        return ans;
    }
};