#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char first[1005],second[1005];
int len1,len2,dp[1005][1005];

int ans(int ind1,int ind2){
    if(ind1==len1 || ind2==len2)
        return 0;
    int &ret=dp[ind1][ind2];
    if(ret!=-1)
        return ret;
    if(first[ind1]==second[ind2])
        ret=1+ans(ind1+1,ind2+1);
    else
        ret=max(ans(ind1+1,ind2),ans(ind1,ind2+1));
    return ret;
}

int main(){
    while(gets(first)){
        memset(dp,-1,1005*1005*4);
        gets(second);
        len1=strlen(first);
        len2=strlen(second);
        printf("%d\n",ans(0,0));
    }
	return 0;
}
