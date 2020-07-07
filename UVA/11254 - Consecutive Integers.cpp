#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n),n!=-1){
        int x=n*2,maxLen=1,mid=n;
        for(long long i=1;i*i<=x;i++){
            if(x%i!=0)
                continue;
            if((x/i)%2==0 && i%2==0)
                continue;
            maxLen=i;
            mid=x/i;
        }
        int s,e;
        if(mid%2){
            s=(mid+1)/2-maxLen/2;
            e=mid/2+maxLen/2;
        }else{
            s=mid/2-maxLen/2;
            e=mid/2+maxLen/2;
        }
        printf("%d = %d + ... + %d\n",n,s,e);
    }
    return 0;
}
