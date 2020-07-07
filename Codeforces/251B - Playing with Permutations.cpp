#include<cstdio>

bool check(int a[],int b[],int n){
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
            return false;
    return true;
}

int main(){
    int n,k,i,j,q[105],target[105],head[105][105],tail[105][105],up=1<<20,down=1<<20;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&q[i]);
    for(i=0;i<n;i++)
        scanf("%d",&target[i]);
    for(i=0;i<n;i++)
        head[0][i]=tail[0][i]=i+1;
    for(i=1;i<=k;i++){
        if(check(head[i-1],target,n)){
            up=i-1;
            break;
        }
        for(j=0;j<n;j++)
            head[i][j]=head[i-1][q[j]-1];
    }
    if(check(head[i-1],target,n))
        up=i-1;
    for(i=1;i<=k;i++){
        if(check(tail[i-1],target,n)){
            down=i-1;
            break;
        }
        for(j=0;j<n;j++)
            tail[i][q[j]-1]=tail[i-1][j];
    }
    if(check(tail[i-1],target,n))
        down=i-1;
    if(up==k || down==k)
        printf("YES\n");
    else if(up>k && down>k)
        printf("NO\n");
    else if(((up<k && (k-up)%2==0) || (down<k && (k-down)%2==0)) && (down>1 || up>1))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
