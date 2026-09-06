#include <bits/stdc++.h>
using namespace std;


int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        long long pre = 0;
        long long after = 0;
        for(int i = 0;i < n / 2;i ++) pre += nums[i];
        for(int i = n / 2;i < n;i ++) after += nums[i];
        if(pre > after) ans ++;
        for(int i = 0;i < n / 2;i ++)
        {
            int num1 = nums[i];
            int num2 = nums[i + n / 2];
            pre -= num1;
            pre += num2;
            after -= num2;
            after += num1;
            if(pre > after) ans ++;
            cout << pre << " " << after << endl;
        }
        return ans;
    }

int main()
{
	vector<int> nums;
	nums = {1,2,3,4,5,6};
	int ans = countGoodRotations(nums);
	cout << ans << endl;
	return 0;
}
