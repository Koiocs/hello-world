#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105,inf=2e9;
char s[N];
int n,ans[N];
int vis[N],chu[N];
vector<int> e1[N],e2[N];
inline bool cmp(int x,int y) {return x>y;}
int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%s",s);
        for (int j=0;j<n;j++) {
            if (s[j]=='+') {
                e1[i].push_back(j);
                e2[j].push_back(i);
                chu[i]++;
            }
        }
    }
    int k=0;
    for (int i=0;i<n;i++) {
        if (chu[i]>chu[k]) k=i;
    }
    int now,tmp=-1;
    for (int i=1;i<=n;i++) {
        if (tmp!=-1) {
            now=-inf;
            for (int j=0;j<e1[tmp].size();j++) {
                int v=e1[tmp][j];
                if (vis[v]) continue;
                if (chu[v]>now) {
                    now=chu[v]; k=v;
                }
            }
        }
        vis[k]=1; ans[i]=k;
        for (int j=0;j<e2[k].size();j++) {
            int v=e2[k][j];
            chu[v]--;
        }
        tmp=k;
    }
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}