#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int line[n + 1];
	vector<string> name(n + 1);
	for(int i = 1;i <= n;i++) cin >> line[i] >> name[i];
	int poi = 1;
	for(int i = 1;i <= m;i++)
	{
		int a,s;
		cin >> a >> s;
		if(a != line[poi]) poi += s;
		else poi += (n - s);
		poi = (poi - 1) % n + 1;
	}
	cout << name[poi] << endl;
	return 0;
}
