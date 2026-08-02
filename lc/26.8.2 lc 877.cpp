



/*
leetcode 877    26.8.2
可以用昨天的代码ac 与昨天相比只多了偶数行 奇数总数的条件
*/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i = 0;i < n;i++) dp[i][i] = piles[i];
        for(int len = 2;len <= n;len++)
        {
            for(int i = 0;i + len - 1< n;i++)
            {
                int j = i + len - 1;
                dp[i][j] = max(piles[i] - dp[i + 1][j],piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
};