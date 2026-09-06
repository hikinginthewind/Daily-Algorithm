#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	bool first = true;
	for(int i = n;i >= 0;i --)
	{
		int a;
		cin >> a;
		if(i == 0)
		{
			if(a == 0) break;
			else if(a < 0) cout << a;
			else if(!first) cout << "+" << a;
			else cout << a;
			break;
		}
		
		if(a == 0) continue;
		else if(a < 0) cout << "-";
		else if(!first) cout << "+";
		a = abs(a);
		if(i == 1)
		{
			if(a != 1) cout << a << "x";
			else cout << "x";
		}
		else if(a != 1) cout << a << "x^" << i;
		else cout << "x^" << i;
		first = false;
	}
	cout << endl;
	return 0;	
} 
