



/*
leetcode 49     26.7.17     hot100
哈希表键为排好顺序的字符串
值为所有排列方式的字符串
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto& s : strs)
        {
            string key = s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& s : mp)
        {
            ans.push_back(s.second);
        }
        return ans;
    }
};