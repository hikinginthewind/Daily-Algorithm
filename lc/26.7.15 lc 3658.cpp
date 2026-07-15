



/*
leetcode 3658   26.7.15
666昨天的那么难今天整个送的题
出题你给我出好了呀
*/
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd = 0;
        int sumeven = 0;
        for(int i = 1;i <= n;i++)
        {
            sumodd += 2 * i - 1;
            sumeven += 2 * i;
        }
        return gcd(sumodd,sumeven);
    }
};