#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e7+7,mod=998244353;
ll n,T,x,y;
ll inv[N],fac[N];
inline ll read(){
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline void exgcd(ll a,ll b) {
    if (b==0) {
        x=1,y=0;
        return ;
    }
    exgcd(b,a%b);
    ll t=x;
    x=y,y=t-a/b*y;
}
inline void init() {
    fac[0]=1;
    for (ll i=1;i<=1e7;i++) {
        fac[i]=(fac[i-1]*i)%mod;
    }
    for (ll i=1;i<=1e7;i++) {
        inv[i]=(inv[i-1]*i%mod+fac[i-1]*(i-1)%mod)%mod;
    }
}
inline ll solve(ll a,ll b) {
    exgcd(a,b);
    return x;
}
int main() {
    T=read(); init();
    while (T--) {
        n=read();
        ll k=solve(fac[n],mod);
        k=(k%mod+mod)%mod;
        printf("%lld\n",inv[n]*k%mod);
    }
    return 0;
}