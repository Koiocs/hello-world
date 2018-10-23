#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,m,cnt=0;
bool vis[N];
string tmp;
string s[N],t[N];
int main() {
    scanf("%d%d",&n,&m); getline(cin,tmp);
    for (int i=1;i<=m;i++) {
        getline(cin,t[i]);
    }
    for (int i=1;i<=m;i++) {
        if (vis[i]) continue;
        for (int j=1;j<=m;j++) {
            if (i==j) continue;
            if (t[i].size()>t[j].size()) continue;
            if (t[i]==t[j].substr(0,t[i].size())) vis[j]=true;
        }
    }
    for (int i=1;i<=m;i++) {
        if (!vis[i]) s[++cnt]=t[i];
    }
    long long ans=pow(10,n);
    for (int i=1;i<=cnt;i++) {
        int k=n-s[i].size();
        long long now=pow(10,k);
        ans-=now;
    }
    printf("%lld",ans);
    return 0;
}