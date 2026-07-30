



/*
leetcode 3014   26.7.30
实际键值其实不需要考虑 只需要考虑不同键值各出现几次
2-8 为一个循环 次数多的贪心放前面
*/
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26,0);
        for(char c : word)
        {
            if(c == '1' || c == '*' || c == '#' || c == '0') continue;
            cnt[c - 'a']++;
        }
        int ans = 0;
        sort(cnt.begin(),cnt.end(),greater<int>());
        for(int i = 1;i <= 4;i++)
        {
            for(int j = 0;j < 8;j++)
            {
                if(i == 4 && (j == 8 || j == 7)) continue;
                int poi = (i - 1) * 8 + j;
                if(poi > 25 || cnt[poi] == 0) break;
                ans += i * cnt[poi];
            }
        }
        return ans;
    }
};