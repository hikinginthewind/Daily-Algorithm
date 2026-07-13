



/*
leetcode 3754   2026.7.7 七月七日晴
今天题简单 把所有不是零的数位集合起来就行
题目中 "如果不存在 非零数字 ，则 x = 0。" 的描述我理解错了
我一开始写的 if 不存在非零数字 return 0
实际上正确理解是这个数字所有数位都是零 那这个数字本身就是零了 x = 0
*/

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        vector<long long> ans;
        int cnt = 0;
        while(n != 0)
        {
            cnt++;
            int a = n % 10;
            n /= 10;
            if(a != 0) ans.push_back(a);
        }
        long long sum = 0;
        for(int i = 0;i < ans.size();i++)
        {
            sum += ans[i];
            long long add = 1;
            for(int j = 0;j < i;j++)
            {
                add *= 10;
            }
            x += ans[i] * add;
        }
        return x * sum;
    }
};
