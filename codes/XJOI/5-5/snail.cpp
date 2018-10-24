#include<bits/stdc++.h>
using namespace std;
const int N=1005,inf=2e9+7;
int n,x,val[N],ord[N],ans[N],tot;
vector<int> edge[N];
inline bool cmp(int x,int y) {
    return val[x]>val[y];
}
inline void dfs(int u,int fa) {
    val[u]=0;
    for (int i=0;i<edge[u].size();i++) {
        int v=edge[u][i];
        if (v==fa) continue;
        dfs(v,u);
    }
    int cnt=0;
    for (int i=0;i<edge[u].size();i++) {
        int v=edge[u][i];
        ord[++cnt]=v;
    }
    sort(ord+1,ord+1+cnt,cmp);
    for (int i=1;i<=cnt;i++) val[u]=max(val[u],val[ord[i]]+i);
}
int main() {
    scanf("%d",&n);
    for (int i=2;i<=n;i++) {
        scanf("%d",&x);
        edge[x].push_back(i);
        edge[i].push_back(x);
    }
    int num=inf;
    for (int i=1;i<=n;i++) {
        dfs(i,-1);
        if (val[i]==num) ans[++tot]=i;
        if (val[i]<num) {
            tot=1; ans[tot]=i;
            num=val[i];
        }
    }
    printf("%d\n",num);
    for (int i=1;i<=tot;i++) printf("%d ",ans[i]);
    return 0;
}