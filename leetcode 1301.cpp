



/*
leetcode 1301   2026.7.5
折磨了很久 一开始想bfs bfs会导致中间点连续入队 不能采用
纯dp遍历 某个点只能从↘ → ↓ 走到 直接双循环遍历 找左 上 左上有意义的点
dp[i][j] = dp[x][y] + board[i][j] (i,j)为靠近出发点的点 (x,y)为靠近终点的点
分数出现更大就更新
路线数根据分数一样大时候加 分数更大时候更新
靠近终点的点没有路线数可能无法到达终点 如 XX 直接跳过
                                      X·
*/

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int m = 1000000007;

        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{0,0}));
        dp[0][0] = {0,1};

        int dx[3] = {-1,0,-1};
        int dy[3] = {0,-1,-1};
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(board[i][j] == 'X' || (i == 0 && j == 0)) continue;
                int val = (board[i][j] >= '1' && board[i][j] <= '9') ? board[i][j] - '0' : 0;

                long long maxscore = -1;
                long long ways = 0;

                for(int k = 0;k < 3;k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 0 && x < n && y >= 0 && y < n && board[x][y] != 'X')
                    {
                        if(dp[x][y].second > 0)
                        {
                            long long newscore = dp[x][y].first + val;
                            if(newscore == maxscore)
                            {
                                ways = (ways + dp[x][y].second) % m;
                            }
                            else if(newscore > maxscore)
                            {
                                maxscore = newscore;
                                ways = dp[x][y].second;
                            }
                        }
                    }
                }
                if(ways != 0) dp[i][j] = {maxscore,ways};
            }
        }
        return {dp[n - 1][n - 1].first,dp[n - 1][n - 1].second};
    }
};


//以下为错误写法 bfs
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int m = 1000000007;
        int n = board.size();
        vector<int> ans(2,0);

        int dx[4] = {-1,0,-1};
        int dy[4] = {0,-1,-1};

        vector<vector<pair<long long,long long>>> dp(n,vector<pair<long long,long long>>(n,{0,0}));
        dp[n - 1][n - 1] = {0,1};

        queue<pair<int,int>> q;
        q.push({n - 1,n - 1});
        while(!q.empty())
        {
            auto t = q.front(); q.pop();
            int nx = t.first; int ny = t.second;
            for(int i = 0;i < 3;i++)
            {
                int x = nx + dx[i];
                int y = ny + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < n && board[x][y] != 'X')
                {
                    if((board[x][y] >= '1' && board[x][y] <= '9') || board[x][y] == 'E' && dp[x][y].second == 0)
                    {
                        dp[x][y].first = (board[x][y] - '0') + dp[nx][ny].first;
                        dp[x][y].second = dp[nx][ny].second;
                    }
                    else if((board[x][y] >= '1' && board[x][y] <= '9') || board[x][y] == 'E' && dp[x][y].second != 0)
                    {
                        int add0 = board[x][y] - '0';
                        int temp = dp[nx][ny].first + add0;
                        if(temp == dp[x][y].first) dp[x][y].second += dp[nx][ny].second;
                        else if(temp > dp[x][y].first)
                        {
                            dp[x][y].first = temp;
                            dp[x][y].second = dp[nx][ny].second;
                        }
                    }
                    if(!(x == 0 && y == 0)) q.push({x,y});
                }
            }
        }
        ans[0] = dp[0][0].first;
        ans[1] = dp[0][0].second;
        ans[0] %= m;
        ans[1] %= m;
        return ans; 
    }
};