/*
最长升序·滑翔之翼
描述

苍穹之上，三人御剑飞行。剑道的高度沿着一条山脉起伏——n 座山峰由西向东排列，高度分别为 h_1, h_2, ..., h_n。从某座山峰出发向东滑翔——每座山只能比前一座更高——问从哪座山出发能滑翔最远？

「最长上升子序列——不过需要求从每个位置出发的结果，」李少白俯瞰山脉，「正向 LIS——dp1[i] 表示以 i 结尾的最长上升子序列长度。反向 LIS——从右向左做一次，dp2[i] 表示以 i 开头的最长上升子序列长度。」

「从 i 出发的最远滑翔距离 = dp2[i]，」赵晴儿计算，「正向 dp1 需要 O(N log N) 的耐心排序法——tails 数组维护。反向 dp2 只需将数组反转后同样处理。」

「两遍 LIS O(N log N)，」梁嘉峰确定起点，「找到 dp2[i] 最大的那个 i 即为最佳起点。若需要求从每个点出发的结果，dp2 数组即是答案。」

滑翔之翼在双向 LIS 的指引下找到最远的翱翔路线。


输入

输入数据第一行是一个平行的整数K，代表有K组测试数据。

每组测试数据包含两行：第一行是一个整数N，代表有N幢建筑。第二行包含N个不同的整数，每一个对应一幢建筑的高度h，按照建筑的排列顺序给出。

数据范围

1≤K≤100

1≤N≤100

0<h<10000


输出

对于每一组测试数据，输出一行，包含一个整数，代表怪盗基德最多可以经过的建筑数量。


输入样例 1 

3
8
300 207 155 299 298 170 158 65
8
65 158 170 298 299 155 207 300
10
2 1 3 4 5 6 7 8 9 10
输出样例 1

6
6
9
提示

原题链接

参考题解

Y总讲解

Y总代码

本题改编自AcWing 1017. 怪盗基德的滑翔翼
董晓讲解: B站视频 — 搜索

来源

xmu
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	cin >> k;
	for(int i = 0;i < k;i++)
	{
		int n;
		cin >> n;
		vector<int> h(n,0);
		vector<int> ans;
		for(int j = 0;j < n;j++)
		{
			cin >> h[j];	
			if(j == 0)
			{
				ans.push_back(h[0]);
				continue;
			}
			int len = ans.size();
			if(ans[len - 1] < h[j]) ans.push_back(h[j]);
			else if(ans[len - 1] > h[j])
			{
				int l = 0,r = len - 1;
				while(l <= r)
				{
					int mid = (l + r) / 2;
					if(ans[mid] > h[j]) r = mid - 1;
					else l = mid + 1;
				}
				ans[l] = h[j];
			}
		}
		reverse(h.begin(),h.end());
		vector<int> ans1;
		ans1.push_back(h[0]);
		for(int j = 0;j < n;j++)
		{
			int len = ans1.size();
			if(ans1[len - 1] < h[j]) ans1.push_back(h[j]);
			else if(ans1[len - 1] > h[j])
			{
				int l = 0,r = len - 1;
				while(l <= r)
				{
					int mid = (l + r) / 2;
					if(ans1[mid] > h[j]) r = mid - 1;
					else l = mid + 1;
				}
				ans1[l] = h[j];
			}
		}
		int l = max(ans.size(),ans1.size());
		cout << l << endl;	
	}
	return 0;	
} 
