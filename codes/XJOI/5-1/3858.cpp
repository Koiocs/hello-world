#include<bits/stdc++.h>
using namespace std;
const int N=105;
string s;
int now=1,r1,r2;
int st[N],top=0,cnt=0;
vector<int> e1[N],e2[N];
inline void make_tree() {
    cin>>s;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='(') st[++top]=++cnt;
        else {
            int y=st[top],x=st[--top];
            if (top>0) e1[x].push_back(y);
            else r1=y;
        }
    }
    cin>>s;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='(') st[++top]=++cnt;
        else {
            int y=st[top],x=st[--top];
            if (top>0) e2[x].push_back(y);
            else r2=y;
        }
    }
}
inline bool check(int u1,int u2) {
    if (e2[u2].size()==0) return true;
    if (e1[u1].size()==0) return false;
    bool flag=true,now=0;
    for (int i=0,j=0;i<e2[u2].size();i++) {
        bool judge=false;
        for (;j<e1[u1].size();j++) {
            int v1=e1[u1][j],v2=e2[u2][i];
            if (check(v1,v2)) {
                judge=true;
                break;
            }
        } j++;
        if (judge==false) {
            flag=false;
            break;
        }
    }
    return flag;
}
int main() {
    make_tree();
    if (check(r1,r2)) printf("Possible\n");
    else printf("Impossible\n");
    return 0;
}