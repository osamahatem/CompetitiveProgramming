#include<cstdio>
#include<algorithm>

using namespace std;

#define eps 1e-9

int main(){
    int n,a[1000],b[1000],lasta,lastb,i;
    double upper=0,lower=1e7,temp,tot=0;
    bool flag1=0,flag2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
        if(i>0){
            if(lastb-b[i]==0){
                lasta=a[i];
                lastb=b[i];
                continue;
            }
            temp=(double)(a[i]-lasta)/(lastb-b[i]);
            if(temp<0){
                printf("-1\n");
                return 0;
            }
            if(lastb<b[i])
                upper=max(upper,temp),flag1=1;
            else
                lower=min(lower,temp),flag2=1;
        }
        lasta=a[i];
        lastb=b[i];
    }
    if(!flag1)
        upper=1e7;
    if(!flag2)
        lower=eps;
    if(lower>upper)
        printf("-1\n");
    else{
        for(i=0;i<n;i++)
            tot+=lower*b[i];
        printf("%g\n",tot);
    }
    return 0;
}
