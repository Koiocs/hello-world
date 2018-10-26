#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=6e5,mod=1e9+7;
ll n,m,C[N][25],a[N];
ll l[N],r[N],k[N],tag[N],ans[N];
inline ll read() {
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline void init() {
    C[0][0]=1;
    for(int i=1;i<=n+210;i++){C[i][0]=1; for(int j=1;j<=min(i,22);j++)C[i][j]=((C[i-1][j-1]+C[i-1][j])%mod+mod)%mod;}
    for(int i=1;i<=22;i++) for(int j=1;j<=n;j++) C[j][i]=C[j+i-1][i];     //这里不是很懂，不过应该是把组合数怎么移动一下吧=w=
}
int main() {
    n=read(),m=read(); init();
    for (ll i=1;i<=m;i++) {
        l[i]=read(),r[i]=read(),k[i]=read();
    }
    for (ll j=20;j>=0;j--) {
        memset(tag,0,sizeof(tag));
        for (ll i=1;i<=m;i++) {
            if (k[i]>=j-1) (tag[r[i]+1]+=mod-C[r[i]-l[i]+1][k[i]-j])%=mod;
            if (k[i]==j) (tag[l[i]]+=1)%=mod;
        }
        for (ll i=1;i<=n;i++) ans[i]=(ans[i]+(ans[i-1]+tag[i])%mod+mod)%mod;
    }
    for (ll i=1;i<=n;i++) printf("%lld\n",(ans[i]%mod+mod)%mod);
    return 0;
}