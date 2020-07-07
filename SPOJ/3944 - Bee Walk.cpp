#include<cstdio>
#include<cstring>

int memo[30][60][15];

int getwalks(int i,int j,int n){
    if(n==0)
        if(i==15 && j==30)
            return 1;
        else
            return 0;
    int &ret=memo[i][j][n];
    if(ret!=-1)
        return ret;
    ret=0;
    ret+=getwalks(i+1,j-1,n-1);
    ret+=getwalks(i+1,j+1,n-1);
    ret+=getwalks(i-1,j-1,n-1);
    ret+=getwalks(i-1,j+1,n-1);
    ret+=getwalks(i,j-2,n-1);
    ret+=getwalks(i,j+2,n-1);
    return ret;
}

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(memo,-1,sizeof(memo));
        printf("%d\n",getwalks(15,30,n));
    }
	return 0;
}
