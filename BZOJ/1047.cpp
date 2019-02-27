#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
#define ll long long
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
inline int gi(){
	int sum=0,f=1;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
#define re register
const int Inf=2e9+10;
int a,b,v[1010][1010],val[1010],mx[1010][1010],mn[1010][1010],pos[1010],n,t1[1010],t2[1010];
inline void pre(){
	re int l,r;
	for(re int i=1;i<=a;i++){
		l=1;r=1;
		for(re int j=1;j<=b;j++){
			while(l<r && val[r-1]<=v[i][j])r--;
			val[r]=v[i][j];pos[r]=j;r++;
			if(pos[l]==j-n)l++;
			if(j>=n)mx[i][j]=val[l];
		}
		l=1;r=1;
		for(re int j=1;j<=b;j++){
			while(l<r && val[r-1]>=v[i][j])r--;
			val[r]=v[i][j];pos[r]=j;r++;
			if(pos[l]==j-n)l++;
			if(j>=n)mn[i][j]=val[l];
		}
	}
}
inline void solve(){
	re int ans=Inf,l,r;
	for(re int i=n;i<=b;i++){
		l=1;r=1;
		for(re int j=1;j<=a;j++){
			while(l<r && val[r-1]>=mn[j][i])r--;
			val[r]=mn[j][i];pos[r]=j;r++;
			if(pos[l]==j-n)l++;
			if(j>=n)t1[j]=val[l];
		}
		l=1;r=1;
		for(re int j=1;j<=a;j++){
			while(l<r && val[r-1]<=mx[j][i])r--;
			val[r]=mx[j][i];pos[r]=j;r++;
			if(pos[l]==j-n)l++;
			if(j>=n)t2[j]=val[l];
		}
		for(re int j=n;j<=a;j++)ans=min(ans,t2[j]-t1[j]);
	}
	printf("%d\n",ans);
}
int main(){
	a=gi();b=gi();n=gi();
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			v[i][j]=gi();
	pre();
	solve();
	return 0;
}
