#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        double d,a,b,f;
        scanf("%d%lf%lf%lf%lf",&n,&d,&a,&b,&f);
        printf("%d %.2f\n",n,d*f/(a+b));
    }
    return 0;
}
