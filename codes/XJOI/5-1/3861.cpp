#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,m,w;
int price[N][N],val[N];
string s;
int main() {
    scanf("%d%d%d",&n,&m,&w);
    for (int i=1;i<=n;i++) {
        cin>>s;
        for (int j=0;j<m;j++) {
            if (s[j]>='a') price[i][j+1]=s[j]-'a'+36;
            else if (s[j]>='A') price[i][j+1]=s[j]-'A'+10;
                 else price[i][j+1]=s[j]-'0';
        }
    }
    for (int k=n;k>=1;k--) {
        int ans=0;
        for (int i=1;i<=7;i++) {
            memset(val,0,sizeof(val));
            for (int j=1;j<=m;j++) {
                int tmp=i;
                while (tmp<=k) {
                    val[j]+=price[tmp][j];
                    tmp+=7;
                }
            }
            sort(val+1,val+1+m);
            ans+=val[1];
        }
        if (ans<=w) {
            cout<<k;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
//23333