#include <bits/stdc++.h>
using namespace std;

int getrank(string c)
{
	if(c == "BangZhu") return 1;
	else if(c == "FuBangZhu") return 2;
	else if(c == "HuFa") return 3;
	else if(c == "ZhangLao") return 4;
	else if(c == "TangZhu") return 5;
	else if(c == "JingYing") return 6;
	else if(c == "BangZhong") return 7;
}
struct per
{
	string name;
	string career;
	int contri;
	int lv;
	int id;	
};
bool cmp1(per a,per b)
{
	if(a.contri == b.contri)
		return a.id < b.id;
	return a.contri > b.contri;
}
bool cmp2(per a,per b)
{
	if(getrank(a.career) == getrank(b.career))
	{
		if(a.lv == b.lv)
			return a.id < b.id;
		return a.lv > b.lv;
	}
	return getrank(a.career) < getrank(b.career);
}

vector<per> all;

bool cmpidx(int a,int b)
{
	return cmp1(all[a],all[b]);
}

int main()
{
	int n;
	cin >> n;
	vector<int> idx;
	for(int i = 0;i < n;i ++)
	{
		string name,career;
		int contri,lv;
		cin >> name >> career >> contri >> lv;
		all.push_back({name,career,contri,lv,i});
		if(career != "BangZhu" && career != "FuBangZhu")
			idx.push_back(i);	
	}
	sort(idx.begin(),idx.end(),cmpidx);
	int m = idx.size();
	for(int i = 0;i < 2 && i < m;i ++)
	{
		all[idx[i]].career = "HuFa";
	}
	for(int i = 2;i < 6 && i < m;i ++)
	{
		all[idx[i]].career = "ZhangLao";
	}
	for(int i = 6;i < 13 && i < m;i ++)
	{
		all[idx[i]].career = "TangZhu";
	}
	for(int i = 13;i < 38 && i < m;i ++)
	{
		all[idx[i]].career = "JingYing";
	}
	for(int i = 38;i < m;i ++)
	{
		all[idx[i]].career = "BangZhong";
	}
	sort(all.begin(),all.end(),cmp2);
	for(int i = 0;i < n;i ++)
	{
		cout << all[i].name << " "
			 << all[i].career << " "
			 << all[i].lv << '\n';
	}
	return 0;
}
