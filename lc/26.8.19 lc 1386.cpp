



/*
leetcode 1386   26.8.19
直接遍历n会tle
只需要遍历每个有预定的排 没预定的ans直接加2
*/
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end());
        int m = reservedSeats.size();
        int ans = 0;
        int poi = 0;
        int cnt = 0;
        while(poi < m)
        {   
            cnt++;
            bool l = false;
            bool ml = false;
            bool mr = false;
            bool r = false;
            int row = reservedSeats[poi][0];
            while(poi < m && reservedSeats[poi][0] == row)
            {
                int seat = reservedSeats[poi][1];
                if(seat == 2 || seat == 3) l = true;
                else if(seat == 4 || seat == 5) ml = true;
                else if(seat == 6 || seat == 7) mr = true;
                else if(seat == 8 || seat == 9) r = true;
                poi++;
            }
            if((l && r && ml) || (l && r && mr) || (l && r && ml && mr) || (ml && mr)) continue;
            else if(!l && !r && !ml && !mr) ans += 2;
            else if((!l && !ml) || (!ml && !mr) || (!mr && !r)) ans++;
        }
        ans += (n - cnt) * 2;
        return ans;
    }
};