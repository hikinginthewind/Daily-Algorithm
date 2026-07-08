



//今天在做项目 没时间学正确代码了 附在明天的一起给


//超时解法
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int m = 1000000007;
        vector<int> ans;
        int n = queries.size();
        for(int i = 0;i < n;i++)
        {
            long long x = 0;
            long long sum = 0;
            for(int j = queries[i][0];j <= queries[i][1];j++)
            {
                if(s[j] == '0') continue;
                x *= 10;
                int temp = s[j] - '0';
                x += temp;
                sum += temp;

                x %= m;
                temp %= m;
            }
            int answer = (sum * x) % m;
            ans.push_back(answer);
        }
        return ans;
    }
};