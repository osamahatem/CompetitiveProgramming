#include<cstdio>

int m,num[31];

void printseq(int i){
    int j=0;
    while(i--){
        printf("%d ",num[j++]);
    }
    printf("1\n");
    return;
}

void seq(int x,int i){
    if(x==1 && i!=0){
        printseq(i);
        return;
    }
    if(x==0 || m==1 || m==0 || x%m){
        printf("Boring!\n");
        return;
    }
    num[i]=x;
    seq(x/m,i+1);
    return;
}

int main(){
    int n;
    while(scanf("%d%d",&n,&m)!=EOF)
        seq(n,0);
    return 0;
}
