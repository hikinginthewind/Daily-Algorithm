



/*
leetcode 3536   26.7.25
数组直接记录 9 - 0 出现的次数
while可以把重复出现的一个数字取出
*/
class Solution {
public:
    int maxProduct(int n) {
        int a[10] = {0};
        while(n != 0)
        {
            a[9 - n % 10]++;
            n /= 10;
        }
        int cnt = 0;
        int ans = 1;
        for(int i = 0;i < 10;i++)
        {
            while(a[i]-- != 0 && cnt != 2)
            {
                cnt++;
                ans *= (9 - i);
            }
            if(cnt == 2) break;
        }
        return ans;
    }
};