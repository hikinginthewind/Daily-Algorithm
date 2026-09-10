#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	cin >> m >> n;
	vector<int> order(m * n);
	for(int i = 0;i < m * n;i ++) cin >> order[i];
	vector<vector<int>> mac(n + 1,vector<int>(m + 1));
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			cin >> mac[i][j];
	int sum = 0;
	vector<vector<int>> tim(n + 1,vector<int>(m + 1));
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
		{
			cin >> tim[i][j];
			sum += tim[i][j];
		}
	vector<int> cnt(n + 1,0);
	vector<int> last(n + 1,0);
	int ans = 0;
	vector<vector<bool>> used(m + 1,vector<bool>(sum + 1,false));
	for(int i = 0;i < m * n;i ++)
	{
		int job = order[i];
		cnt[job] ++;
		int k = cnt[job];
		int x = mac[job][k];
		int t = tim[job][k];
		for(int j = last[job] + 1;j + t - 1 <= sum;j ++)
		{
			if(!used[x][j])
			{
				bool ok = true;
				for(int p = j;p <= j + t - 1;p ++)
				{
					if(used[x][p])
					{
						ok = false;
						break;
					}
				}
				if(ok)
				{
					for(int p = j;p <= j + t - 1;p ++)
					{
						used[x][p] = true;
					}
					last[job] = j + t - 1;
					ans = max(ans,last[job]);
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;	
} 
