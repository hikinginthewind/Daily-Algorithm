



/*
leetcode 1979   26.7.18
依旧一天地狱一天天堂
简单到没什么可以总结
*/
class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return gcd(nums[0],nums[nums.size() - 1]);
    }
};