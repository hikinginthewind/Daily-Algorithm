#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<char> s;
	char c;
	while(scanf("%c",&c) != EOF) s.push_back(c);
	int n = s.size();
	int ans1 = 0,ans2 = 0;
	for(int i = 0;i < n;i ++)
	{
		if(s[i] == 'b' || i + 1 < n && s[i + 1] == 'o' || i + 2 < n && s[i + 2] == 'y')
			ans1 ++;
		if(s[i] == 'g' || i + 1 < n && s[i + 1] == 'i' || i + 2 < n && s[i + 2] == 'r' || i + 3 < n && s[i + 3] == 'l')
			ans2 ++;
	}
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}
