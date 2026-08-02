/*
线性DP·防御阵列
描述

边关告急！n 枚不同高度的敌方灵箭迎面袭来。守关大阵有两种防御模式：升序模式——拦截的灵箭高度必须严格递增（从低到高）；降序模式——拦截的灵箭高度必须严格递减（从高到低）。一套防御系统只能以一种模式运行。问至少需要几套系统才能拦截全部灵箭？

「这比单纯的最长升/降子序列更复杂，」李少白神情凝重，「每枚灵箭可以被分配到任意一套系统中——只要它在该系统中符合升序或降序的要求。」

「迭代加深 DFS！」赵晴儿眼中灵光一闪，「从答案 ans=1 开始尝试，用 DFS 判断能否用 ans 套系统拦截所有灵箭。对于每枚灵箭，依次尝试放入已有的升序系统、已有的降序系统，或新开一套系统。」

「剪枝很关键，」梁嘉峰补充，「记录每套升序系统的当前最大高度、降序系统的当前最小高度。将灵箭放入升序系统时，贪心选择当前高度最大但仍小于灵箭的那套；放入降序系统时，贪心选择当前高度最小但仍大于灵箭的那套——这叫最优性剪枝。」

「n ≤ 50，搜索空间虽大但剪枝有力，」李少白拔剑指天，「布阵！」


输入

输入包含多组测试用例。

对于每个测试用例，第一行包含整数nn，表示来袭导弹数量。

第二行包含nn个不同的整数，表示每个导弹的高度。

当输入测试用例n=0n=0时，表示输入终止，且该用例无需处理。

数据范围

1≤n≤50


输出

对于每个测试用例，输出一个占据一行的整数，表示所需的防御系统数量。


输入样例 1 

5
3 5 2 4 1
0 
输出样例 1

2
提示

对于给出样例，最少需要两套防御系统。

一套击落高度为3,4的导弹，另一套击落高度为5,2,1的导弹。

原题链接

参考题解

acwing讲解

本题改编自AcWing 1010. 拦截导弹
董晓讲解: B站视频 — E56 线性DP 导弹防御系统

来源

xmu
*/

/*
xmu 134		26.8.2
dfs 
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n;
int h[N];
int up[N],down[N];

bool dfs(int depth,int u,int su,int sd)
{
	if(su + sd > depth) return false;
	if(u == n) return true;
	
	bool flag = false;
	for(int i = 1;i <= su;i++)
	{
		if(up[i] < h[u])
		{
			int t = up[i];
			up[i] = h[u];
			if(dfs(depth,u + 1,su,sd)) return true;
			up[i] = t;
			flag = true;
			break;
		}
	}
	if(!flag)
	{
		up[su + 1] = h[u];
		if(dfs(depth,u + 1,su + 1,sd)) return true;
	}
	flag = false;
	for(int i = 1;i <= sd;i++)
	{
		if(down[i] > h[u])
		{
			int t = down[i];
			down[i] = h[u];
			if(dfs(depth,u + 1,su,sd)) return true;
			down[i] = t;
			flag = true;
			break;
		}
	}
	if(!flag)
	{
		down[sd + 1] = h[u];
		if(dfs(depth,u + 1,su,sd + 1)) return true;
	}
	return false; 
}

int main()
{
	cin >> n;
	int t;
	int i = 0;
	while(cin >> t)
	{
		if(t == 0) break;
		h[i++] = t;
	}
	int depth = 0;
	while(!dfs(depth,0,0,0)) depth++;
	cout << depth << endl;
	return 0;
}
