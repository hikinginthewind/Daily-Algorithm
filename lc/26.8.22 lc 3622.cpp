



/*
leetcode 3622   26.8.22
模拟软柿子
*/
class Solution {
public:
    bool checkDivisibility(int n) {
        int m = n;
        int num1 = 0;
        int num2 = 1;
        while(m != 0)
        {
            int temp = m % 10;
            m /= 10;
            num1 += temp;
            num2 *= temp;
        }
        int num = num1 + num2;
        if(num != 0 && n % num == 0) return true;
        else return false;
    }
};