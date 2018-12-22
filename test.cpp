#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
inline int gi()
{
	int sum=0,f=1;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
#define ll long long
ll n;int k,c[130],cnt;
bool vis[130];
struct node{
	ll val;int x,y,z;
	bool operator<(const node b)const{
		return val<b.val;
	}
};
priority_queue<node>q;
int main()
{
	scanf("%lld%d",&n,&k);
	for(int i=2;i<128;i++)
	{
		if(!vis[i])
		{
			ll x=i;c[++cnt]=i;
			for(int j=1;x<=n;j++,x*=i)q.push((node){x,i,j,cnt-1});
		}
		for(int j=i*i;j<128;j+=i)vis[j]=1;
	}
	while(k--)
	{
		node now=q.top();q.pop();
		if(!k)printf("%lld\n",now.val);
		else if(now.y>1)for(int i=1;i<=now.z;i++)q.push((node){now.val/now.x*c[i],now.x,now.y-1,i});
	}
	return 0;
}
