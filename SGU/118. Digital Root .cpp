#include<cstdio>

int dig_sum(long long a){
    int ret=0;
    while(a>0){
        ret+=a%10;
        a/=10;
    }
    return ret;
}

int dig_root(long long a){
    int ret=dig_sum(a);
    if(ret>9)
        return dig_root((long long)ret);
    return ret;
}

int main(){
    int t,n,i;
    long long arr[1000],temp,x;
    scanf("%d",&t);
    while(t--){
        temp=1;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&x);
            temp*=dig_root(x);
            temp=dig_root(temp);
            arr[i]=temp;
        }
        temp=0;
        for(i=0;i<n;i++)
            temp+=arr[i];
        printf("%d\n",dig_root(temp));
    }
    return 0;
}
