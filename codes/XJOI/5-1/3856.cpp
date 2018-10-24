#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
    getline(cin,s);
    int sz=s.size();
    bool flag1=false;
    for (int i=0;i<sz;i++) {
        if (s[i]=='S') {
            flag1=true;
            bool flag2=false;
            for (int j=i+1;j<sz;j++) {
                if (s[j]=='A') {
                    flag2=true;
                    bool flag3=false;
                    for (int k=sz-1;k>=j+1;k--) {
                        if (s[k]=='N') {
                            flag3=true;
                            cout<<s; cout<<"TA";
                            break;
                        }
                    }
                    if (!flag3) {
                        for (int l=0;l<=j;l++) cout<<s[l];
                        cout<<"NTA";
                        for (int l=j+1;l<sz;l++) cout<<s[l];
                    }
                    break;
                }
            }
            if (!flag2) {cout<<s; cout<<"ANTA";}
            break;
        }
    }
    if (!flag1) {cout<<s; cout<<"SANTA";}
    return 0;
}