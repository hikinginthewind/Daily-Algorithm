



/*
leetcode 3090   26.8.14
第一百题
双指针滑动窗口+哈希表
*/
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int m[26] = {0};
        int n = s.size();
        int l = 0;
        int len = 0;
        for(int r = 0;r < n;r++)
        {
            m[s[r] - 'a']++;
            if(m[s[r] - 'a'] <= 2)
            {
                len = max(len,r - l + 1);
            }
            else
            {
                while(m[s[r] - 'a'] > 2 && l < r)
                {
                    m[s[l] - 'a']--;
                    l++;
                }
            }
        }
        return len;
    }
};