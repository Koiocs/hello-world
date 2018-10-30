//luogu3933
#include<bits/stdc++.h>
using namespace std;
#define rep(q,w,e) for(int q=(w);q<=(e);q++)
const int N=2e3+7,inf=1e9+7;
int n,m,minn,maxx;
int val[N][N],tmp[N][N],kinf[N][N];
inline int read() {
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline void Rotate() {
    rep(i,1,n) rep(j,1,m) {
        tmp[j][n+1-i]=val[i][j];
    }
    swap(n,m);
    rep(i,1,n) rep(j,1,m) {
        val[i][j]=tmp[i][j];
    }
}
inline bool check(int x) {
    int min1=inf,min2=inf,max1=-inf,max2=-inf;
    rep(i,1,n) rep(j,1,m) {
        if (kind[i][j]) {
            min1=min(min1,val[i][j]);
            max1=max(max1,val[i][j]);
        }
        else {
            min2=min(min2,val[i][j]);
            max2=max(max2,val[i][j]);
        }
    }
    if (max1-min1>x || max2-min2>x) return false;
    return true;
}
inline bool judge(int x) {
    int now=m;
    memset(kind,0,sizeof(kind));
    rep(i,1,n) rep(j,1,m) {
        if (j>now) break;
        if (val[i][j]+x<=maxx) kind[i][j]=1;
        else now=j-1;
    }
    if (check(x)) return true;
    now=0;
    memset(kind,0,sizeof(kind));
    rep(i,1,n) rep(j,1,m) {
        if (j>now) break;
        if (val[i][j]-x<=minn) kind[i][j]=1;
        else now=j-1;
    }
    if (check(x)) return true;
    return false;
}
inline void solve() {
    int l=0,r=maxx-minn,res=inf;
    while (l<=r) {
        int mid=(l+r)/2;
        if (judge(mid)) {
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return res;
}
int main() {
    n=read(),m=read();
    maxx=-inf,minn=inf;
    rep(i,1,n) rep(i,1,m) {
        val[i][j]=read();
        maxx=max(maxx,val[i][j]);
        minn=min(minn,val[i][j]);
    }
    int ans=inf;
    ans=min(ans,solve()); Rotate();
    ans=min(ans,solve()); Rotate();
    ans=min(ans,solve()); Rotate();
    ans=min(ans,solve()); printf("%d\n",ans);
    return 0;
}