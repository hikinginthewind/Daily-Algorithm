



/*
leetcode 486    26.8.1
最优基本确定dp
dp[i][j] 表示的是从下标 i - j 的 1 相对 2 的最大得分
对于每个长度的子序列 dp 从短更新到长每次拿 i 位置或 j 位置的nums
dp则更新为更大的 nums[i/j] - dp[i + 1/i][j/j - 1]
*/
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0;i < n;i++) dp[i][i] = nums[i];
        for(int len = 2;len <= n;len++)
        {
            for(int i = 0;i + len - 1 < n;i++)
            {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j],nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};