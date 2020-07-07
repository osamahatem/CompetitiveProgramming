#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,p=2,c=0;
    cin>>n;
    while(n>1 && p*p<=n){
        while(n%p==0){
            n/=p;
            c++;
        }
        if(c)
            printf("%d^%d\n",p,c);
        p++;
        c=0;
    }
    if(n>1)
        printf("%d^1\n",n);
    return 0;
}
