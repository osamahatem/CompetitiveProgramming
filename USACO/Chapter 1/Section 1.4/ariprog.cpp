/*
ID: 19semse1
PROG: ariprog
LANG: C++
*/

#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    int n,m,i,j,temp,c;
    bool isbisq[130000],flag=0;
    memset(isbisq,0,sizeof(isbisq));
    scanf("%d%d",&n,&m);
    for(i=0;i<=m;i++)
        for(j=i;j<=m;j++){
            temp=i*i+j*j;
            isbisq[temp]=1;
        }
    for(i=1;i<=2*m*m/(n-1);i++){
        j=0;
        while(j+i*(n-1)<=2*m*m){
            temp=j;
            c=0;
            while(temp<=2*m*m && c<n && isbisq[temp]){
                temp+=i;
                c++;
            }
            if(c==n){
                printf("%d %d\n",j,i);
                flag=1;
            }
            j++;
        }
    }
    if(!flag)
        printf("NONE\n");
    return 0;
}
