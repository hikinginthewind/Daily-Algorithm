



/*
leetcode 3345   26.8.6
t 不大于 10 至多10次就可以找到答案 直接翻译题目就行
*/
class Solution {
public:
    int smallestNumber(int n, int t) {
        int k = n;
        while(n)
        {
            int temp = 1;
            int m = n;
            while(m != 0)
            {
                temp *= (m % 10);//刚开始答案错因为 *= 写成 *
                m /= 10;
            }
            if(temp % t == 0)
            {
                break;
            }
            else if(n < k + t) n++;
        }
        return n;
    }
};