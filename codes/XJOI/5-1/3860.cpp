#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)
typedef long long ll;
const ll N=2e5+7,B=1e5+7;
ll n,seed,m;
ll a[N],s[N],c[N];
inline ll read(){
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline void add(ll x,ll v) {
    while (x<=2e5+7) {
        c[x]+=v;
        x+=lowbit(x);
    }
}
inline ll sum(ll x) {
    ll res=0; 
    while (x>0) {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
int main() {
    n=read(),seed=read(),m=read();
    for (ll i=1;i<=n;i++) {
        a[i]=(seed/(1ll<<16))%m;
        seed=(seed*1103515245+12345)%(1ll<<31);
    }
    ll ans=0;
    for (ll i=0;i<m;i++) {
        memset(c,0,sizeof(c));
        add(0+B,1);
        for (ll j=1;j<=n;j++) {
            s[j]=s[j-1]+(a[j]==i);
            ll k=2*s[j]-j+B;
            add(k,1); ans+=sum(k-1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}