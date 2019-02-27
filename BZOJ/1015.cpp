#include<bits/stdc++.h>
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);
using namespace std;
const int maxm=200010,maxn=2*maxm;
int beat[maxn],front[maxn];
int f[maxn];
int find(int x){
    if(f[x]!=x)f[x]=find(f[x]);
    return f[x];
}
int ans[maxn];
void join(int x,int y){
    x=find(x);y=find(y);
    if(x!=y)f[y]=x;
}
struct node{
    int to,next,now;
}e[maxn];
int cnt,die[maxn];
void Add(int x,int y){
    e[++cnt].to=y;
    e[cnt].next=front[x];
    front[x]=cnt;
    e[cnt].now=x;
}
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){ 
        int x,y;
        scanf("%d%d",&x,&y);
        Add(x,y);
        Add(y,x);
    } 
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        scanf("%d",&beat[i]);
        die[beat[i]]=1;
    }
    for(i=0;i<=n;i++)
        f[i]=i;
    int tot=n-k;
    for(i=1;i<=2*m;i++)
        if(!die[e[i].to] && !die[e[i].now]){
            int u=e[i].now,v=e[i].to;
            if(find(u)!=find(v)){
                tot--;join(u,v);
            }
        }
    ans[k+1]=tot;
    for(i=k;i>=1;i--){
        int u=beat[i];
        tot++;
        die[u]=0;
        for(j=front[u];j;j=e[j].next){
            int v=e[j].to;
            if(!die[v] && find(u)!=find(v)){
                tot--;
                join(u,v);
            }
        }
        ans[i]=tot;
    }
    for(i=1;i<=k+1;i++)printf("%d\n",ans[i]);
    return 0;
}
