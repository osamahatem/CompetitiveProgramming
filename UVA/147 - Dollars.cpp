#include<cstdio>
#include<cstring>
#include<cmath>

int coins[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long memo[11][30001];

long long ans(int coin,int left){
    if(left==0)
        return 1;
    if(coin==11 || left<0)
        return 0;
    long long &ret=memo[coin][left];
    if(ret!=-1)
        return ret;
    return ret=ans(coin,left-coins[coin])+ans(coin+1,left);
}

int main(){
    float in;
    int val;
    memset(memo,-1,11*30001*sizeof(long long));
    while(scanf("%f",&in),val=(int)(floor(in*100+0.5)))
        printf("%6.2f%17lld\n",in,ans(0,val));
	return 0;
}
