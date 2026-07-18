/*
描述

青石镇外的三才剑阵前，赵晴儿指着三排玉柱：「这三排玉柱分别刻着A、B、C三列数字。剑阵的开启条件是——从A选一个数Ai，从B选一个数Bj，从C选一个数Ck，使得 Ai < Bj < Ck。问共有多少种选择组合？」

李少白沉吟道：「若用三重循环枚举——O(N3)便是天荒地老。」他绕着玉柱走了一圈，「不妨以B列为轴——对每个Bj，统计A中小于Bj的个数，乘以C中大于Bj的个数。」

「妙哉！」梁嘉峰在沙盘上画出计数之法，「先将A和C各自排序。对每个Bj，在A中二分查找——小于Bj的元素个数为cntA；在C中二分查找——大于Bj的元素个数为cntC。Bj的贡献便是cntA × cntC。」

赵晴儿补充：「也可用前缀和计数——预先计算每个值在A中出现了多少次，再求前缀和。对于Bj，直接查表得小于Bj的A元素个数——O(1)！同理C做后缀计数。总复杂度O(N log N)。」

「从三列中各取一数，形成递增之势——」李少白总结，「以中轴Bj为核心，左右夹击。剑道讲究'以中驭外'，算法亦然。」

给定三个整数数组A、B、C，求满足Ai < Bj < Ck的三元组数量。


输入

第一行包含一个整数 N。

第二行包含 N 个整数 A?, A?, ..., A?。

第三行包含 N 个整数 B?, B?, ..., B?。

第四行包含 N 个整数 C?, C?, ..., C?。



数据范围

数据范围1≤N≤10^5,

0≤Ai,Bi,Ci≤10^5


输出

一个整数表示答案。


输入样例 1 

3
1 1 1
2 2 2
3 3 3
输出样例 1

27
提示

原题链接

Y总讲解

来源

xmu
*/







#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	int b[n];
	int c[n];
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a,a + n);
	for(int i = 0;i < n;i++)
	{
		cin >> b[i];
	}
	for(int i = 0;i < n;i++)
	{
		cin >> c[i];
	}
	sort(c,c + n);
	long long ans = 0;
	for(int i = 0;i < n;i++)
	{
		int target = b[i];
		int l = 0,r = n - 1;
		int cntA,cntC;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(a[mid] >= target)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		cntA = l;// 循环结束时，l 就是第一个 >= target 的下标，也就是小于 target 的个数
		l = 0;
		r = n - 1;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(c[mid] > target)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		cntC = n - l;// 循环结束时，l 就是第一个 > target 的下标
		ans += 1LL * cntA * cntC;
	}
	cout << ans << endl;
	return 0;
} 

/*

AI 的前缀和解法 
原 A C 数组元素映射为符合元素个数
用前缀和计算时间复杂度 o(n) 

const int MAXV = 100000;
int cntA[MAXV+2] = {0}, cntC[MAXV+2] = {0};
for (int x : a) cntA[x]++;
for (int x : c) cntC[x]++;

for (int i = 1; i <= MAXV; i++) cntA[i] += cntA[i-1];        // 前缀和
for (int i = MAXV-1; i >= 0; i--) cntC[i] += cntC[i+1];     // 后缀和

long long ans = 0;
for (int x : b) {
    int less = (x == 0) ? 0 : cntA[x-1];   // 严格小于 x
    int greater = cntC[x+1];               // 严格大于 x
    ans += 1LL * less * greater;
}
*/
