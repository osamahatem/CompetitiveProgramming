#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,d,x,sum=0;
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        sum+=x;
    }
    sum+=10*(n-1);
    if(sum>d)
        printf("-1\n");
    else
        printf("%d\n",(d-sum+10*(n-1))/5);
    return 0;
}
