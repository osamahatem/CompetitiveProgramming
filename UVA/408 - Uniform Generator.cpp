#include<cstdio>
#include<cstdlib>

int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int main(){
    int step,mod;
    while(scanf("%d%d",&step,&mod)!=EOF){
        if(gcd(step,mod)==1)
            printf("%10d%10d    Good Choice\n\n",step,mod);
        else
            printf("%10d%10d    Bad Choice\n\n",step,mod);
    }
    return 0;
}
