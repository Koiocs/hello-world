#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100;
ll n,a[N],b[N];
bool f[N][N][2];
inline ll read() {
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline int failed() {
    printf("Impossible\n");
    return 0;
}
int main() {
    n=read();
    for (ll i=1;i<=n;i++) a[i]=read();
    for (ll i=1;i<=n;i++) b[i]=read()-a[i];
    memset(f,true,sizeof(f));
    for (ll i=1;i<=n;i++) {
        for (ll j=0;j<=62;j++) {
            ll k=(1ll<<j);
            if (!(a[i]&k) && (b[i]&k)) return failed();
            if (!(a[i]&k) && !(b[i]&k)) f[i][j][1]=f[i+1][j][1]=false,f[i+1][j][0]=f[i][j][0];
            if ((a[i]&k) && !(b[i]&k)) f[i+1][j][1]=f[i][j][0],f[i+1][j][0]=f[i][j][1];
            if ((a[i]&k) && (b[i]&k)) f[i+1][j][0]=f[i][j][0]=false,f[i+1][j][1]=f[i][j][1];
            if (!f[i][j][0] && !f[i][j][1]) return failed();
        }
    }
    printf("Possible\n");
    return 0;
}