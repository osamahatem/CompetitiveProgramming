#include<cstdio>
#include<cmath>

int main(){
    int a,b,w,x,c,cycle=0,ans,hi,lo,mid;
    double inc=0.0;
    scanf("%d%d%d%d%d",&a,&b,&w,&x,&c);
    if(b>=x){
        cycle+=((b-x)/x)+1;
        b-=cycle*x;
        cycle+=(x-b)/(w-x);
        inc+=(x-b)/(w-x);
        if((x-b)%(w-x)!=0){
            inc+=1.0;
            cycle++;
        }
    }else{
        cycle+=(x-b)/(w-x);
        inc+=(x-b)/(w-x);
        if((x-b)%(w-x)!=0){
            inc+=1.0;
            cycle++;
        }
        b+=cycle*(w-x);
        cycle+=((b-x)/x)+1;
    }
    inc/=cycle;
    hi=1<<30,lo=0;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if((c-mid)<=(int)(ceil(a-mid*inc))){
            ans=mid;
            hi=mid-1;
        }else
            lo=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
