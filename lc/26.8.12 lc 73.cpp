



/*
leetcode 73 26.8.12
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> k;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(matrix[i][j] == 0)
                    k.push_back({i,j});
        for(auto t : k)
        {
            int x = t.first;
            int y = t.second;
            for(int i = 0;i < m;i++)
                matrix[i][y] = 0;
            for(int i = 0;i < n;i++)
                matrix[x][i] = 0;
        }
        return;
    }
};