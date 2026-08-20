



/*
leetcode 3069   26.8.20
模拟题
*/
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> bef;
        vector<int> aft;
        bef.push_back(nums[0]);
        aft.push_back(nums[1]);
        for(int i = 2;i < n;i++)
        {
            int n1 = bef.size() - 1;
            int n2 = aft.size() - 1;
            if(bef[n1] > aft[n2]) bef.push_back(nums[i]);
            else aft.push_back(nums[i]);
        }
        vector<int> ans;
        for(int i = 0;i < bef.size();i++) ans.push_back(bef[i]);
        for(int i = 0;i < aft.size();i++) ans.push_back(aft[i]);
        return ans;
    }
};