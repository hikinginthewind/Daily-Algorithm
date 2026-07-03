
/*
leetcode 3620	2026.7.3 
二分(最大最小值) + DAG(有向无环图)
mid = 当前区间路径分数中值
拓扑排列：0 - n-1 中的 u到下一个节点 v 的最小分数
dist[v] = dist[u] + w
dist[n - 1]为 0 - n-1的最小分数总和 需小于 k

！！！
n 为 online.size() 不为 edges 中最大的结点值 
LLONG_MAX为无穷大值
unique的使用 重复值移最后 返回不重复最后一位的后一位
check cost[mid] 因为检查分数 
*/ 
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        vector<int> cost;
        int n = online.size();
        for(auto e : edges)
        {
            cost.push_back(e[2]);
        }

        sort(cost.begin(),cost.end());
        cost.erase(unique(cost.begin(),cost.end()),cost.end());

        int l = 0,r = cost.size() - 1;
        int ans = -1;

        auto check = [&](int mincost) -> bool
        {
            vector<vector<pair<int,int>>> adj(n);
            vector<int> indeg(n,0);

            for(auto& t : edges)
            {
                int u = t[0],v = t[1],w = t[2];
                if(w < mincost) continue;
                if(u >= 0 && u < n && online[u] == false) continue;
                if(v >= 0 && v < n && online[v] == false) continue;
                adj[u].push_back({v,w});
                indeg[v]++;
            }

            vector<long long> dist(n,LLONG_MAX);
            dist[0] = 0;

            queue<int> q;
            for(int i = 0;i < n;i++)
            {
                if(indeg[i] == 0) q.push(i);
            }
            
            while(!q.empty())
            {
                int u = q.front(); q.pop();
                for(auto& [v,w] : adj[u])
                {
                    if(dist[u] != LLONG_MAX)
                    {
                        if(dist[v] - dist[u] > w)
                        {
                            dist[v] = dist[u] + w;
                        }
                    }
                    indeg[v]--;
                    if(indeg[v] == 0) q.push(v);
                }
            }

            return dist[n - 1] <= k;
        };

        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(check(cost[mid]))
            {
                ans = cost[mid];
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};