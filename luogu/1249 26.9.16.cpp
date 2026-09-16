#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int sum = 0;
	vector<int> ans;
	for(int i = 2;i <= n;i ++)
	{
		
		if(sum + i > n)
		{
			int m = ans.size();
			int cnt = n - sum;
			while(cnt - m >= 0)
			{
				cnt -= m;
				for(int j = m - 1;j >= 0;j --)
				{
					ans[j] ++;
				}
			}
			for(int j = m - 1;j > m - cnt - 1;j --)
			{
				ans[j] ++;
			}
			break;
		}
		else
		{
			ans.push_back(i);
			sum += i;
		}
	}
	vector<int> res;
	res.push_back(ans[0]);
	int carry = 0;
	for(int i = 0;i < ans.size();i ++)
	{
		printf("%d",ans[i]);
		if(i != ans.size() - 1) printf(" ");
		if(i != 0)
		{
			int len = res.size();
			for(int j = 0;j < len;j ++)
			{
				int tmp = res[j] * ans[i] + carry;
				res[j] = tmp % 10;
				carry = tmp / 10;
			}
			while(carry != 0)
			{
				res.push_back(carry % 10);
				carry /= 10;
			}
		}
	}
	printf("\n");
	for(int i = res.size() - 1;i >= 0;i --)
	{
		printf("%d",res[i]);
	}
	printf("\n");
	return 0;
} 
