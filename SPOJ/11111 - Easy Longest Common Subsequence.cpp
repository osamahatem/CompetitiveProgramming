#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
    char x[10],y[10];
    scanf("%s%s",x,y);
    int lx=strlen(x),ly=strlen(y),lcs[10][10],i,j;
    for(i=0;i<=lx;i++)
        lcs[i][0]=0;
    for(i=0;i<=ly;i++)
        lcs[0][i]=0;
    for(i=1;i<=lx;i++){
        for(j=1;j<=ly;j++){
            if(x[i-1]==y[j-1])
                lcs[i][j]=lcs[i-1][j-1]+1;
            else
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    printf("%d\n",lcs[lx][ly]);
	return 0;
}
