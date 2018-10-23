#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,a[N],p[N];
inline bool cmp(int x,int y) {return x>y;}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n,cmp);
    int cnt=0;
    for (int i=a[1];i;i>>=1) {
        p[++cnt]=i%2;
    }
    for (int i=2;i<=n;i++) {
        int tmp=a[i];
        for (int j=cnt;j>=1;j--) {
            if (p[j]==0 && pow(2,j-1)<=tmp) {
                p[j]=1;
                tmp-=pow(2,j-1);
            }
        }
    }
    int ans=0;
    for (int i=1;i<=cnt;i++) {
        if (p[i]==1) ans+=pow(2,i-1);
    }
    printf("%d\n",ans);
    return 0;
}
//2333