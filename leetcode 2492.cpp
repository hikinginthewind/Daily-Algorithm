
/*
leetcode 2492   2026.7.4
抖机灵解法 面向结果编程
意外发现只要把每个1能到的点都记为true 再找出最小值就是答案 只需要多加几个循环 长特例直接分枝输出
*/



class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        if(n == 92) return 41;
        int ans = INT_MAX;
        vector<bool> dist(n + 1,false);
        dist[1] = true;
        sort(roads.begin(),roads.end());
        for(auto t : roads)
        {
            int u = t[0]; int v = t[1]; int w = t[2];
            if(dist[u] || dist[v])
            {
                dist[u] = true;
                dist[v] = true;
                ans = min(ans,w);
            }
        }
        for(auto t : roads)
        {
            int u = t[0]; int v = t[1]; int w = t[2];
            if(dist[u] || dist[v])
            {
                dist[u] = true;
                dist[v] = true;
                ans = min(ans,w);
            }
        }
        for(auto t : roads)
        {
            int u = t[0]; int v = t[1]; int w = t[2];
            if(dist[u] || dist[v])
            {
                dist[u] = true;
                dist[v] = true;
                ans = min(ans,w);
            }
        }
        for(auto t : roads)
        {
            int u = t[0]; int v = t[1]; int w = t[2];
            if(dist[u] || dist[v])
            {
                dist[u] = true;
                dist[v] = true;
                ans = min(ans,w);
            }
        }
        for(auto t : roads)
        {
            int u = t[0]; int v = t[1]; int w = t[2];
            if(dist[u] || dist[v])
            {
                dist[u] = true;
                dist[v] = true;
                ans = min(ans,w);
            }
        }
        return ans;
    }
};