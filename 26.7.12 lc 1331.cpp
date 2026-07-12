



/*
leetcode 1331   2026.7.12
简单题 t = nlogn
暴力双for循环会超时 排好位的数组里面二分
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> a = arr;
        sort(a.begin(),a.end());
        auto t = unique(a.begin(),a.end());
        a.erase(t,a.end());
        for(int i = 0;i < n;i++)
        {
            int l = 0,r = a.size() - 1;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                if(a[mid] == arr[i])
                {
                    arr[i] = mid + 1;
                    break;
                }
                else if(arr[i] < a[mid]) r = mid - 1;
                else l = mid + 1;
            }
        }
        return arr;
    }
};

/*
7.10再尝试 依旧TLE。。。。。。。
目前能力应该够不到 连解答也不太看得懂 以后再战
*/

超出时间限制
673 / 682 个通过的测试用例
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> g(n);
        for(int i = 0;i < n;i++)
        {
            g[i] = {nums[i],i};
        }
        sort(g.begin(),g.end());
        vector<vector<int>> spl;
        vector<int> line;
        for(int i = 0;i < n;i++)
        {
            if(line.empty()) line.push_back(g[i].first);
            else
            {
                int poi = g[i].first;
                int num = g[i].second;
                if(i != 0 && poi - g[i - 1].first <= maxDiff) line.push_back(poi);
                else
                {
                    spl.push_back(line);
                    line.clear();
                    line.push_back(g[i].first);
                }
            }
        }
        if(!line.empty()) spl.push_back(line);

        vector<vector<int>> newqueries;
        vector<int> ans(queries.size(),-1);
        for(int i = 0;i < queries.size();i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            int s_po = nums[start];
            int e_po = nums[end];
            int MAX = max(s_po,e_po);
            int MIN = min(s_po,e_po);
            s_po = MIN;
            e_po = MAX;
            newqueries.push_back({s_po,e_po});
            if(s_po == e_po && start != end) newqueries[i].push_back(1);
            else newqueries[i].push_back(0);
        }
        for(int i = 0;i < queries.size();i++)
        {
            int cnt = 0;

            int start = newqueries[i][0];
            int end = newqueries[i][1];
            if(start == end && newqueries[i][2] == 1)
            {
                ans[i] = 1;
                continue;
            }
            int l = 0;
            int r = spl.size() - 1;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                if(spl[mid][0] == start || (mid < r && spl[mid][0] <= start && spl[mid + 1][0] > start) || (mid == r) && spl[mid][0] <= start)
                {
                    cnt = mid;
                    break;
                }
                if(spl[mid][0] >= start)
                {
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            int len = spl[cnt].size();
            if(spl[cnt][len - 1] >= end && spl[cnt][0] <= end)
            {
                if(end == start) ans[i] = 0;
                else if(end - start <= maxDiff) ans[i] = 1;
                else
                {
                    int start_poi = lower_bound(spl[cnt].begin(),spl[cnt].end(),start) - spl[cnt].begin();
                    int end_poi = lower_bound(spl[cnt].begin(),spl[cnt].end(),end) - spl[cnt].begin();

                    int res = 0;
                    int next = start_poi;
                    while(next < end_poi)
                    {
                        auto nxt = upper_bound(spl[cnt].begin() + next,spl[cnt].begin() + end_poi + 1,maxDiff + spl[cnt][next]);
                        next = (nxt - 1) - spl[cnt].begin();
                        res++;
                    }
                    ans[i] = res;
                }
            }
        }
        return ans;
    }
};