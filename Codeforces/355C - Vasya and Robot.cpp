#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,i,l,r,ql,qr,w[100000],left[100001],right[100001],temp,cost=2000000000,extra;
    scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr);
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
    left[0]=0;
    right[n]=0;
    for(i=1;i<=n;i++)
        left[i]=left[i-1]+w[i-1]*l;
    for(i=n-1;i>=0;i--)
        right[i]=right[i+1]+w[i]*r;
    for(i=0;i<=n;i++){
        temp=left[i]+right[i];
        if(n-i>i){
            extra=n-2*i-1;
            temp+=extra*qr;
        }else if(i>n-i){
            extra=2*i-n-1;
            temp+=extra*ql;
        }
        cost=min(cost,temp);
    }
    printf("%d\n",cost);
	return 0;
}
