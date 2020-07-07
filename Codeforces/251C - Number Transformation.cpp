#include<cstdio>
#include<algorithm>

using namespace std;

int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}

long long solve(long long up,long long down,int k){
    long long ret=0;
    int i,maxi;
    while(up>down){
        maxi=1;
        for(i=2;i<=k;i++){
            if(up%i>maxi && up%i<=up-down)
                maxi=up%i;
        }
        up-=maxi;
        ret++;
    }
    return ret;
}

int main(){
    long long a,b;
    int k,lcm=1,x,i;
    scanf("%I64d%I64d%d",&a,&b,&k);
    for(i=2;i<=k;i++){
        x=lcm*i;
        x/=gcd(lcm,i);
        lcm=x;
    }
    long long step=solve(lcm,0,k),up=a/lcm*lcm,down=b/lcm*lcm;
    if(down<b)
        down+=lcm;
    long long ans;
    if(up<down)
        ans=solve(a,b,k);
    else
        ans=(up-down)/lcm*step+solve(a,up,k)+solve(down,b,k);
    printf("%I64d\n",ans);
    return 0;
}
