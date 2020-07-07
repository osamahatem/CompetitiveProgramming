#include<cstdio>
#include<cmath>

int main(){
    int r,i;
    long long m;
    double ans,hyp,temp;
    scanf("%I64d%d",&m,&r);
    hyp=2*(r*r);
    hyp=sqrt(hyp);
    ans=2*m*r;
    for(i=1;i<m;i++){
        temp=2*i*r;
        if(i>1)
            temp+=2*hyp-2*r;
        else
            temp+=hyp;
        ans+=2*(m-i)*temp;
    }
    ans/=m*m;
    printf("%.10f\n",ans);
	return 0;
}
