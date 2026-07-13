




//。。。超时代码
// 673/682 我真没招了 写了一天 明天补题
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
                    int templ = start_poi;
                    int tempr = start_poi;
                    while(tempr < end_poi)
                    {
                        if(spl[cnt][tempr] - spl[cnt][templ] <= maxDiff)
                        {
                            if(tempr < len && spl[cnt][tempr + 1] - spl[cnt][templ] > maxDiff)
                            {
                                templ = tempr;
                                res++;
                            }
                            else if(tempr < len && spl[cnt][tempr + 1] - spl[cnt][templ] <= maxDiff) tempr++;
                        }
                    }
                    if(tempr == end_poi && spl[cnt][tempr] - spl[cnt][templ] <= maxDiff) res++;
                    ans[i] = res;
                }
            }
        }
        return ans;
    }
};

//理解题目错误写的代码
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> g(n);
        for(int i = 0;i < n;i++)
        {
            g[i] = {nums[i],i};
        }
        sort(g.begin(),g.end());
        vector<vector<pair<int,int>>> spl;
        vector<pair<int,int>> line;
        for(int i = 0;i < n;i++)
        {
            if(line.empty()) line.push_back(g[i]);
            else
            {
                int poi = g[i].first;
                int num = g[i].second;
                if(i != 0 && poi - g[i - 1].first <= maxDiff) line.push_back(g[i]);
                else
                {
                    spl.push_back(line);
                    line.clear();
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
        }
        for(int i = 0;i < queries.size();i++)
        {
            int cnt = 0;

            int start = newqueries[i][0];
            int end = newqueries[i][1];
            int l = 0;
            int r = spl.size() - 1;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                if(spl[mid][0].first >= start)
                {
                    cnt = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            int len = spl[cnt].size();
            if(spl[cnt][len - 1].first >= end && spl[cnt][0].first <= end) ans[i] = end - start;
        }
        return ans;
    }
};
