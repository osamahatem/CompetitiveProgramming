#include<cstdio>

int main(){
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int n,m,i,cur_day=0;
    scanf("%d%d",&n,&m);
    m--;
    if(m>=12 || n>days[m]){
        printf("Impossible\n");
        return 0;
    }
    for(i=0;i<m;i++)
        cur_day+=days[i];
    cur_day+=n-1;
    printf("%d\n",cur_day%7+1);
    return 0;
}
