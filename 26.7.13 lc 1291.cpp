



/*
leetcode 1291   2026.7.13
从low找到high容易超时
直接遍历所有符合条件的数 范围内的放进答案即可
*/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 1;i <= 9;i++)
        {
            int num = i;
            for(int j = num + 1;j <= 9;j++)
            {
                num = num * 10 + j;
                if(num > high) break;
                if(num >= low) ans.push_back(num);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};