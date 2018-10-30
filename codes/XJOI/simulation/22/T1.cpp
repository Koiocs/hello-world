//luogu3944
#include<bits/stdc++.h>
using namespace std;
#define rep(q,w,e) for(int q=(w);q<=(e);q++)
const int N=5e6+7;
int n,m,ans,a[N];
inline int read() {
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline bool judge(int x) {
    int sum=0;
    rep(i,1,n) {
        if (a[i]%3==1 && a[i]/3<=x) sum+=1;;
        if (a[i]%3==2 && a[i]/3<=x) sum+=2;
        if (a[i]%3==0 && a[i]!=0 && a[i]/3<=x+1) sum+=3;
    }
    if (sum<m) return false;
    return true;
}
int main() {
    n=read(),m=read();
    rep(i,1,n) a[i]=read();
    int l=0,r=10005; ans=-1;
    while (l<r) {
        int mid=(l+r)/2;
        if (judge(mid)) r=mid,ans=mid;
        else l=mid+1;
    }
    if (ans==-1) printf("-1\n");
    else {
        int num1=0,num2=0,num3=0;
        rep(i,1,n) {
            if (a[i]%3==1 && a[i]/3<=ans) num1++;
            if (a[i]%3==2 && a[i]/3<=ans) num2++;
            if (a[i]%3==0 && a[i]!=0 && a[i]/3<=ans+1) num3++;
        }
        int sum=num1+num2*2+num3*3;
        while (sum-m>=3 && num3) {num3--; sum-=3;}
        while (sum-m>=1 && num1) {num1--; sum-=1;}
        while (sum-m>=2 && num2) {num2--; sum-=2;}
        int cost=num1+num2+num3*4+ans;
        printf("%d %d\n",ans,cost);
    }
    return 0;
}
