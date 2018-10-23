#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=55,mod=1e9+7;
string s;
ll a[N],f[N][N][N],ans=0;
int main() {
    cin>>s; ll m=s.size();
    for (ll i=0;i<m;i++) {
        ll x=(s[i]-'0')%3;
        a[i+1]=x; f[i+1][1][x]=1;
    }
    for (ll l=2;l<=m;l++) {
        for (ll i=l;i<=m;i++) {
            for (ll j=1;j<i;j++) {
                for (ll k=0;k<3;k++) {
                    if (f[j][l-1][k]==0) continue;
                    ll x=(a[i]+k)%3;
                    (f[i][l][x]+=f[j][l-1][k])%=mod;
                }
            }
        }
    }
    ll ans=0;
    for (ll i=1;i<=m;i++) {
        for (ll j=1;j<=i;j++) {
            ans=(ans+f[i][j][0])%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}