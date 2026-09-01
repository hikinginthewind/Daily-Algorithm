#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> ans;
	vector<int> fac;
	fac.push_back(1);
	int carry = 0;
	int car = 0;
	for(int num = 1;num <= n;num ++)
	{
		int i = 0,j = 0;
		while(i <= fac.size() - 1)
		{
			int temp = fac[i] * num;
			temp += carry;
			fac[i] = temp % 10;
			carry = temp / 10; 
			i ++;
		}
		while(carry != 0)
			{
				fac.push_back(carry % 10);
				carry /= 10;
			} 
		if(ans.size() < fac.size()) ans.resize(fac.size(),0); 
		while(j <= fac.size() - 1)
		{
			int temp = fac[j] + ans[j] + car;
			ans[j] = temp % 10;
			car = temp / 10;
			j ++; 
		}
		while(car != 0)
			{
				ans.push_back(car % 10);
				car /= 10;
			}
	}
	reverse(ans.begin(),ans.end());
	for(int i = 0;i < ans.size();i ++)
		cout << ans[i];
	cout << endl; 
	return 0;	
} 
