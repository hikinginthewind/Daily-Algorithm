



/*
leetcode 1081   26.7.19
入栈出栈
*/
class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string stk;
        vector<int> lastime(26,0);
        for(int i = 0;i < n;i++)
        {
            lastime[s[i] - 'a'] = i;
        }
        vector<bool> used(26,false);
        for(int i = 0;i < n;i++)
        {
            char c = s[i];
            int idx = c - 'a';
            if(used[idx]) continue;
            while(!stk.empty() && stk.back() > c && lastime[stk.back() - 'a'] > i)
            {
                used[stk.back() - 'a'] = false;
                stk.pop_back();
            }
            stk.push_back(c);
            used[idx] = true;
        }
        return stk;
    }
};