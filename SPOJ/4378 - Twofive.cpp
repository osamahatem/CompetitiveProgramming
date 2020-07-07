#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int dp[6][6][6][6][6];
string str="";

int gen_ways(int r1,int r2,int r3,int r4,int r5){
    if(r1==5 && r2==5 && r3==5 && r4==5 && r5==5)
        return 1;
    int &ret=dp[r1][r2][r3][r4][r5];
    if(ret!=-1)
        return ret;
    ret=0;
    if(r1<5)
        ret+=(gen_ways(r1+1,r2,r3,r4,r5));
    if(r2<r1 && r2<5)
        ret+=(gen_ways(r1,r2+1,r3,r4,r5));
    if(r3<r2 && r3<5)
        ret+=(gen_ways(r1,r2,r3+1,r4,r5));
    if(r4<r3 && r4<5)
        ret+=(gen_ways(r1,r2,r3,r4+1,r5));
    if(r5<r4 && r5<5)
        ret+=(gen_ways(r1,r2,r3,r4,r5+1));
    return ret;
}

void get_str(int r1,int r2,int r3,int r4,int r5,int &order){
    if(r1==5 && r2==5 && r3==5 && r4==5 && r5==5)
        return;
    if(dp[r1][r2][r3][r4][r5]<order)
        return;
    char x=r1+r2+r3+r4+r5+'A';
    str+=x;
    if(r1<5)
        get_str(r1+1,r2,r3,r4,r5,order);
    if(r2<r1 && r2<5)
        get_str(r1,r2+1,r3,r4,r5,order);
    if(r3<r2 && r3<5)
        get_str(r1,r2,r3+1,r4,r5,order);
    if(r4<r3 && r4<5)
        get_str(r1,r2,r3,r4+1,r5,order);
    if(r5<r4 && r5<5)
        get_str(r1,r2,r3,r4,r5+1,order);
    return;
}

int main(){
    memset(dp,-1,sizeof dp);
    gen_ways(0,0,0,0,0);
    int order;
    scanf("%d",&order);
    //get_str(0,0,0,0,0,order);
    //printf("%s\n",str.c_str());
	return 0;
}
