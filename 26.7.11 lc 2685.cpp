



/*
leetcode 2685   2026.7.12
今天没空 学习ai生成代码
union的时候把每一个连线的两端进行比较得到父端
find是一个辅助函数 每次都找到最上层的父端
昨天的明天看
*/

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n,1);
        for(int i = 0;i < n;i++)
        {
            parent[i] = i;
        }
        function<int(int)> find = [&](int x) -> int{
            while(parent[x] != x)
            {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };
        auto unionset = [&](int x,int y)
        {
            int rx = find(x),ry = find(y);
            if(rx == ry) return;
            if(rank[rx] < rank[ry])
            {
                parent[rx] = ry;
            }
            else if(rank[rx] > rank[ry])
            {
                parent[ry] = rx;
            }
            else{
                parent[ry] = rx;
                rank[rx]++;
            }
        };
        for(auto& e : edges)
        {
            unionset(e[0],e[1]);
        }
        unordered_map<int,vector<int>> comp_vertices;
        for(int i = 0;i < n;i++)
        {
            comp_vertices[find(i)].push_back(i);
        }
        unordered_map<int,int> com_edges;
        for(auto& e : edges)
        {
            int root = find(e[0]);
            com_edges[root]++;
        }
        int ans = 0;
        for(auto& kv : comp_vertices)
        {
            int root = kv.first;
            vector<int>& verts = kv.second;
            int v = verts.size();
            int e = com_edges[root];
            if(e == v * (v - 1) / 2) ans++;
        }
        return ans;
    }
};