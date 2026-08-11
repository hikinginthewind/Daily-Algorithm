#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,v;
	cin >> n >> v;
	int w[n];
	int V[n];
	int s[n];
	for(int i = 0;i < n;i++)
		cin >> w[i] >> V[i] >> s[i];
	vector<int> val;
	vector<int> weig;
	for(int i = 0;i < n;i++)
	{
		int k = 1; 
		while(s[i] > k)
		{
			val.push_back(k * V[i]);
			weig.push_back(k * w[i]);
			s[i] -= k;
			k *= 2;
		}
		val.push_back(s[i] * V[i]);
		weig.push_back(s[i] * w[i]); 
	}
	int cnt = val.size();
	vector<int> dp(v + 1,0);
	for(int i = 0;i < cnt;i++)
	{
		for(int j = v;j >= weig[i];j--)
		{
			dp[j] = max(dp[j],dp[j - weig[i]] + val[i]);
		}
	}
	cout << dp[v] << endl; 
	return 0;	
} 
