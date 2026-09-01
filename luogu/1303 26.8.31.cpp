#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin >> a >> b;
	if(a == "0" || b == "0")
	{
		cout << 0 << endl;
		return 0;
	}
	int n = a.size();
	int m = b.size();
	vector<int> ans(n + m + 1,0);
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int i = 0,j = 0;
	int carry = 0;
	for(int i = 0;i < n;i ++)
	{
		for(int j = 0;j < m;j ++)
		{
			int numa = a[i] - '0';
			int numb = b[j] - '0';
			ans[i + j] += numa * numb;
		}
	}
	for(int i = 0;i <= n + m;i ++)
	{
		ans[i] += carry;
		carry = ans[i] / 10;
		ans[i] %= 10;
	}
	bool find = false;
	for(int i = m + n;i >= 0;i --)
	{
		if(find) cout << ans[i];
		else if(ans[i] != 0)
		{
			find = true;
			cout << ans[i];
		}
	}
	cout << endl;
	return 0;
}
