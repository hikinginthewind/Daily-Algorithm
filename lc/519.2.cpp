//超时。。。 

#include <bits/stdc++.h>
using namespace std;

long long minOperations(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0;i < n;i ++)
        {
            int num = nums[i];
            string aba = to_string(num);
            int len = aba.size();
            cout << "len :" << len << endl;
            bool p = true;
            for(int poi = 0;poi < len;poi ++)
            {
                if(aba[poi] != aba[len - poi - 1])
                {
                    p = false;
                    break;
                }
            }
            int num_up = num + 2;
            int num_down = num - 2;
            while(!p)
            {
                p = true;
                ans ++;
                string up = to_string(num_up);
                string down = to_string(num_down);
                int len_up = up.size();
                int len_down = down.size();
                cout << "lenup:" << len_up << " " << "len_down:" << len_down << endl;
                for(int poi = 0;poi < len_up;poi ++)
                {
                    if(up[poi] != up[len_up - poi - 1])
                    {
                        p = false;
                        break;
                    }
                }
                if(p) break;
                p = true;
                for(int poi = 0;poi < len_down;poi ++)
                {
                    if(down[poi] != down[len_down - poi - 1])
                    {
                        p = false;
                        break;
                    }
                }
                if(p) break;
                cout << "numup:" << num_up << " " << "numdown:" << num_down;
                cout << endl;
                cout << i << " ans:" << ans;
				cout << endl;
                num_up += 2;
                num_down -= 2;
            }
        }
        return ans;
}

int main()
{
	vector<int> nums;
	nums.push_back(10);
	nums.push_back(12);
	nums.push_back(14);
	nums.push_back(16);
	long long ans = minOperations(nums);
	cout << ans << endl;
	return 0;
} 



/*
第三问超时 
class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0;i < n;i ++)
        {
            int num1 = nums[i];
            for(int j = i + 1;j < n;j ++)
            {
                int num2 = nums[j];
                if(num2 < num1) break;
                else if(num2 > num1) ans ++;
            }
        }
        return ans;
    }
};
*/ 
