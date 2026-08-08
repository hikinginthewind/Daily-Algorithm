



/*
leetcode 189    26.8.8
昨天没做完的后几天补 这两天在火车上
今天的题有进阶做法
AB -> BA
对A单独翻转 结果是A倒置
对AB倒转 结果是B(倒转)A(倒转)
则只需要对nums倒转 再对前k个倒转和后n-k个倒转即可
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return;
        k %= n;
        vector<int> ans(n);
        for(int i = 0;i < n;i++)
        {
            int poi = (i + k) % n;
            ans[poi] = nums[i];
        }
        nums = ans;
    }
};