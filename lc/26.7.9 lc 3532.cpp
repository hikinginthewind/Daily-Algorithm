



/*
leetcode 3532   2026.7.9
思路一开始就确定了 但处理细节处理了很久
暴力for循环会超时 考虑二分锁定出发点的位置
每次 j = lines中出发点坐标大于aim的右端点
锁定找到lines中比aim大的最小点
然后在lines[j]里面循环找到另一端点
*/
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<vector<int>> lines;
        vector<int> line = {};
        for(int i = 0;i < n;i++)
        {
            int r = i + 1;
            if(line.empty()) line.push_back(i);
            if(r < n && nums[r] - nums[i] <= maxDiff) line.push_back(r);
            else
            {
                if(!line.empty()) lines.push_back(line);
                line = {};
            }
        }
        int m = queries.size();
        vector<bool> ans(m,false);
        for(int i = 0;i < m;i++)
        {
            if(queries[i][0] == queries[i][1])
            {
                ans[i] = true;
                continue;
            }
            int left = 0;
            int right = lines.size() - 1;
            int aim = queries[i][0];
            int j;
            while(left <= right)
            {
                int mid = (left + right) / 2;
                if(lines[mid][0] == aim)
                {
                    j = mid;
                    break;
                }
                if(lines[mid][0] > aim)
                {
                    right = mid - 1;
                    j = mid;
                }
                else left = mid + 1;
                j = right;
            }
            int r = queries[i][1];
            int len = lines[j].size();
            if(r <= lines[j][len - 1] && r >= lines[j][0])
            {
                ans[i] = true;
            }
        }
        return ans;
    }
};

//超时代码
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<vector<int>> lines;
        vector<int> line = {};
        for(int i = 0;i < n;i++)
        {
            int r = i + 1;
            if(line.empty()) line.push_back(i);
            if(r < n && nums[r] - nums[i] <= maxDiff) line.push_back(r);
            else
            {
                if(!line.empty()) lines.push_back(line);
                line = {};
            }
        }
        int m = queries.size();
        vector<bool> ans(m,false);
        for(int i = 0;i < m;i++)
        {
            if(queries[i][0] == queries[i][1])
            {
                ans[i] = true;
                continue;
            }
            int left = 0;
            int right = lines.size() - 1;
            int aim = queries[i][0];
            int j;
            while(left <= right)
            {
                int mid = (left + right) / 2;
                if(lines[mid][0] == aim)
                {
                    j = mid;
                    break;
                }
                if(lines[mid][0] > aim) right = mid - 1;
                else left = mid + 1;
            }
            j = left;
            int r = queries[i][1];
            int len = lines[j].size();
            if(r <= lines[j][len - 1] && r >= lines[j][0])
            {
                ans[i] = true;
                break;
            }
        }
        return ans;
    }
};


/*昨天没做完的
主要思路是 前缀和
把原字符串中非零的元素 单独提取到一个数组
用原字符串的非零数前缀和数组作为新数组的下标
同时 A 为每个非零数字的集合
P 为非零数字组成整数的前缀和数组
sumA 为和的前缀和数组
precnt 为原数组到某一位的非零数字数 用来计算得到新下标
*/
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        string so = s;
        const int mod = 1000000007;
        int m = s.size();

        vector<int> precnt(m + 1,0);
        vector<int> A;

        vector<long long> P(1,0);
        vector<long long> sumA(1,0);

        for(int i = 0;i < m;i++)
        {
            if(s[i] != '0')
            {
                int d = s[i] - '0';
                A.push_back(d);
                P.push_back((P.back() * 10 + d) % mod);
                sumA.push_back(sumA.back() + d);
                precnt[i + 1] = precnt[i] + 1;
            }
            else precnt[i + 1] = precnt[i];
        }

        int maxlen = A.size() + 1;
        vector<long long> pow10(maxlen,1);
        for(int i = 1;i < maxlen;i++)
        {
            pow10[i] = pow10[i - 1] * 10 % mod;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for(auto& q : queries)
        {
            int l = q[0],r = q[1];
            int cnt = precnt[r + 1] - precnt[l];
            if(cnt == 0) ans.push_back(0);
            else{
                int L = precnt[l];
                int R = precnt[r + 1] - 1;
                int k = R - L + 1;
                long long x = (P[R + 1] - P[L] * pow10[k]) % mod;
                if(x < 0) x+= mod;

                long long digsum = sumA[R + 1] - sumA[L];
                long long res = (x * (digsum % mod)) % mod;
                ans.push_back(int(res));
            }
        }
        return ans;
    }
};
