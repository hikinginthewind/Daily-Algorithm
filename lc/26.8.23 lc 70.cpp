



/*
leetcode 70     26.8.23
复杂数学题没写出来 写个简单题
*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i <= n;i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
/*
待完成：leetcode 1927. 求和游戏
*/