#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,na,nb;
	cin >> n >> na >> nb;
	int a[na];
	int b[nb];
	for(int i = 0;i < na;i ++) cin >> a[i];
	for(int i = 0;i < nb;i ++) cin >> b[i];
	int ans_a = 0;
	int ans_b = 0;
	int poia = 0;
	int poib = 0;
	for(int i = 0;i < n;i ++)
	{
		poia = i % na;
		poib = i % nb;
		if(a[poia] == b[poib]) continue;
		else if(a[poia] == 0 && (b[poib] == 2 || b[poib] == 3) || 
		a[poia] == 1 && (b[poib] == 3 || b[poib] == 0) || 
		b[poib] == 4 && (a[poia] == 2 || a[poia] == 3) || 
		a[poia] == 2 && b[poib] == 1 || 
		a[poia] == 3 && b[poib] == 2 || 
		a[poia] == 4 && (b[poib] == 0 || b[poib] == 1)) ans_a ++;
		else ans_b ++;
	}
	cout << ans_a << " " << ans_b << endl;
	return 0;	
} 
