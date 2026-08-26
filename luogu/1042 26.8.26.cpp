#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<char> com;
	char c;
	while(scanf("%c",&c))
	{
		if(c == 'E') break;
		if(c == 'W' || c == 'L') com.push_back(c);
	}
	int n = com.size();
	if(n == 0)
	{
		cout << "0:0" << "\n\n" << "0:0" << endl;
		return 0;
	}
	int preout = 0;
	int aftout = 0;
	for(int i = 0;i < n;i++)
	{
		if(com[i] == 'W') preout ++;
		else if(com[i] == 'L') aftout ++;
		if((preout >= 11 || aftout >= 11) && abs(preout - aftout) >= 2)
		{
			cout << preout << ":" << aftout << endl;
			preout = 0;
			aftout = 0;
		}
		if(i == n - 1)
		{
			cout << preout << ":" << aftout << endl;
			preout = 0;
			aftout = 0;
		}
	}
	cout << endl; 
	for(int i = 0;i < n;i++)
	{
		if(com[i] == 'W') preout ++;
		else if(com[i] == 'L') aftout ++;
		if((preout >= 21 || aftout >= 21) && abs(preout - aftout) >= 2)
		{
			cout << preout << ":" << aftout << endl;
			preout = 0;
			aftout = 0;
		}
		if(i == n - 1)
		{
			cout << preout << ":" << aftout << endl;
			preout = 0;
			aftout = 0;
		}
	}
	return 0;
}
