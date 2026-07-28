



/*
leetcode 3517   26.7.28
刚开始想用unique 但会被塞垃圾值到队尾
哈希表记录字符出现次数
奇数放一个在中间
偶数对半先加在头 反转后再拼到奇数值后方
*/
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> a(26,0);
        int mid = -1;
        for(int c : s) a[c - 'a']++;
        for(int t = 0;t < 26;t++)
            if(a[t] % 2) mid = t;
        string ans;
        string half;
        for(int t = 0;t < 26;t++)
        {
            ans.append(a[t] / 2,t + 'a');
        }
        half = ans;
        if(mid != -1) ans += (mid + 'a');
        reverse(half.begin(),half.end());
        ans += half;
        return ans;
    }
};