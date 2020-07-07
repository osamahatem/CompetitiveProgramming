#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int c,q,d,n,p;
        cin>>c;
        q=c/25;
        c-=q*25;
        d=c/10;
        c-=d*10;
        n=c/5;
        c-=n*5;
        p=c;
        printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",t,q,d,n,p);
    }
    return 0;
}
