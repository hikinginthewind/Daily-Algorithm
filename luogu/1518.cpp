#include <bits/stdc++.h>
using namespace std;
int main()
{
	int sx,sy;
	int fx,fy;
	vector<vector<char>> g(10,vector<char>(10));
	for(int i = 0;i < 10;i ++)
		for(int j = 0;j < 10;j ++)
		{
			cin >> g[i][j];
			if(g[i][j] == 'F')
			{
				sx = i;
				sy = j;
			}
			else if(g[i][j] == 'C')
			{
				fx = i;
				fy = j;
			}
		}
	int dx[4] = {-1,0,1,0};
	int dy[4] = {0,1,0,-1};
	queue<vector<int>> q;
	int forw_j = 0;
	int forw_c = 0;
	q.push({sx,sy,fx,fy,forw_j,forw_c});
	int ans = -1;
	bool used[10][10][10][10][4][4] = {};
	while(!q.empty())
	{
		auto t = q.front();
		q.pop();
		int x1 = t[0];
		int y1 = t[1];
		int fx1 = t[2];
		int fy1 = t[3];
		forw_j = t[4];
		forw_c = t[5];
		
		if(used[x1][y1][fx1][fy1][forw_j][forw_c])
		{
			cout << "0" << endl;
			return 0;
		}
		else used[x1][y1][fx1][fy1][forw_j][forw_c] = true;
		
		ans ++;
		
		if(x1 == fx1 && y1 == fy1) break;
		
		int x = x1 + dx[forw_j];
		int y = y1 + dy[forw_j];
		bool pj = false;
		if(x < 0 || x >= 10 || y < 0 || y >= 10 || g[x][y] == '*')
		{
			forw_j = (forw_j + 1) % 4;
			pj = true;
		}
		
		int newfx = fx1 + dx[forw_c];
		int newfy = fy1 + dy[forw_c];
		bool pf = false;
		if(newfx < 0 || newfx >= 10 || newfy < 0 || newfy >= 10 || g[newfx][newfy] == '*')
		{
			forw_c = (forw_c + 1) % 4;
			pf = true;	
		} 
		
		if(!pj)
		{
			x1 = x;
			y1 = y;
		}
		if(!pf)
		{
			fx1 = newfx;
			fy1 = newfy;
		}
		q.push({x1,y1,fx1,fy1,forw_j,forw_c});
	}
	cout << ans << endl;
	return 0;	
} 
