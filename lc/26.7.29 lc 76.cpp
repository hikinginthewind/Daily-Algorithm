



/*
leetcode 76     26.7.29
滑动窗口
r 向右更新
l 向右收缩
ascil码直接映射数组
维护两个window和need
needcnt 为win和ne中count相等的个数
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(),m = t.size();
        if(n < m) return "";
        int need[128] = {0};
        int needcnt = 0;
        for(char c : t)
        {
            need[c]++;
        }
        for(int i : need)
        {
            if(i > 0) needcnt++;
        }
        int minlen = INT_MAX;
        int start = 0;
        int l = 0;
        int r = 0;
        int window[128] = {0};
        while(r < n)
        {
            char c = s[r];
            window[c]++;
            if(need[c] > 0 && window[c] == need[c])
            {
                needcnt--;
            }
            while(needcnt == 0)
            {
                char tra = s[l];
                window[tra]--;
                if(need[tra] > 0 && window[tra] < need[tra]) needcnt++;
                if(r - l + 1 < minlen)
                {
                    minlen = r - l + 1;
                    start = l;
                }
                l++;
            }
            r++;
        }
        return minlen != INT_MAX ? s.substr(start,minlen) : "";
    }
};