#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> ans(m);
	for(int i = 0;i < m;i ++) scanf("%d",&ans[i]);
	sort(ans.begin(),ans.end());
	for(int i = 0;i < m;i ++)
	{
		printf("%d",ans[i]);
		if(i != m - 1) printf(" ");
	}
	printf("\n");
	return 0;
}
