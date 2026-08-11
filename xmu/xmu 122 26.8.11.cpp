#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,v;
	cin >> n >> v;
	int V[n];
	int w[n];
	for(int i = 0;i < n;i++)
		cin >> V[i] >> w[i];
	int dp[v + 1] = {0};
	for(int i = 0;i < n;i++)
	{
		for(int j = V[i];j <= v;j++)
		{
			dp[j] = max(dp[j],dp[j - V[i]] + w[i]);
		}
	}
	cout << dp[v] << endl;
	return 0;	
} 
