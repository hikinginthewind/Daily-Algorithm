#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l,r;
    scanf("%d%d",&l,&r);
    int ans = 0;
    for(int i = l;i <= r;i ++)
    {
        int temp = i;
        while(temp != 0)
        {
            if(temp % 10 == 2) ans ++;
            temp /= 10;
        }
    }
    printf("%d\n",ans);
    return 0;
}
