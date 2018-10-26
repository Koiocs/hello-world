#include<bits/stdc++.h>
using namespace std;
#define N 1005
int n,m,q,cnt=0;
bitset<N> f[N],g[N],s;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main() {
    n=read(),m=read(),q=read();
    for (int i=1;i<=m;i++) {
        int x=read(),y=read();
        g[x][y]=1,g[y][x]=1;
    }
    while (q--) {
        int k=read(),maxx=-1;
        while (k--) {
            int x=read(),dis=read();
            dis=min(n,dis);
            maxx=max(maxx,dis);
            f[dis][x]=1;
        }
        for (int i=maxx;i>=1;i--) {
            if (f[i].count()==n) {
                f[0]=f[i];
                break;
            }
            s=f[i]^f[i+1];
            while (s.count()) {
                int pos=s._Find_first();
                f[i-1]|=g[pos];
                s[pos]=0;
            }
            f[i-1]|=f[i];
        }
        cout<<f[0].count()<<endl;
        for (int i=0;i<=maxx;i++) f[i].reset();
    }
    return 0;
}