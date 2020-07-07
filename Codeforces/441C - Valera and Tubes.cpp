#include<bits/stdc++.h>

using namespace std;

int n,m,k;

void next(int &r,int &c){
    if(r%2==0)
        c--;
    else
        c++;
    if(c<1){
        r++;
        c++;
    }else if(c>m){
        r++;
        c--;
    }
    return;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    int r=1,c=1,area=n*m;
    while(k>1){
        printf("2 %d %d",r,c);
        next(r,c);
        printf(" %d %d\n",r,c);
        next(r,c);
        area-=2;
        k--;
    }
    printf("%d",area);
    for(int i=0;i<area;i++){
        printf(" %d %d",r,c);
        next(r,c);
    }
    printf("\n");
    return 0;
}


