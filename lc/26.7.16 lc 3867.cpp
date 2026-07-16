



/*
leetcode 3867   26.7.16
每次更新最大值就行了 翻译题目没意思
*/
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int maxnow = 0;
        for(int i = 0;i < n;i++)
        {
            maxnow = max(maxnow,nums[i]);
            prefixGcd[i] = gcd(nums[i],maxnow);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long ans = 0;
        int l = 0;
        int r = prefixGcd.size() - 1;
        while(l < r)
        {
            ans += gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};