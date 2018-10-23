#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
char s[N];
int n,k=-1,ans[N];
int vis[N],ord[N],chu[N];
vector<int> e1[N],e2[N];
inline bool cmp(int x,int y) {
    return vis[x]<vis[y] || vis[x]==vis[y] && chu[x]>chu[y];
}
int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%s",s); ord[i]=i;
        for (int j=0;j<n;j++) {
            if (s[j]=='+') {
                e1[i].push_back(j);
                e2[j].push_back(i);
                chu[i]++;
            }
        }
    }
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) {
        sort(ord,ord+n,cmp);
        for (int j=0;j<e1[k].size();j++) {
            
        }
        vis[k]=1; ans[i]=k;
        for (int j=0;j<e[k].size();j++) {
            int v=e[k][j];
            chu[v]--;
        }
    }
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}