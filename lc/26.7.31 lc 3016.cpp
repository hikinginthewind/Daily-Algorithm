



/*
leetcode 3016   26.7.31
emmmm其实昨天的代码直接就能过
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