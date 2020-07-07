#include<cstdio>

bool flag[5]={0,0,0,0,0};

bool valid(int i,int j, int n){
    if(i==n || j==n) return false;
    if(i<0 || j<0) return false;
    return true;
}

void check(char square[][10],int i,int j,int n){
    flag[0]=0;
    flag[1]=0;
    flag[2]=0;
    flag[3]=0;
    flag[4]=0;
    if(valid(i-1,j,n)){
        if(square[i-1][j]<='E' && square[i-1][j]!='.')
            flag[square[i-1][j]-'A']=1;
    }
    if(valid(i+1,j,n)){
        if(square[i+1][j]<='E' && square[i+1][j]!='.')
            flag[square[i+1][j]-'A']=1;
    }
    if(valid(i,j-1,n)){
        if(square[i][j-1]<='E' && square[i][j-1]!='.')
            flag[square[i][j-1]-'A']=1;
    }
    if(valid(i,j+1,n)){
        if(square[i][j+1]<='E' && square[i][j+1]!='.')
            flag[square[i][j+1]-'A']=1;
    }
}

int main(){
    int t,T,n,i,j,k;
    char square[10][10];
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d ",&n);
        for(i=0;i<n;i++)
            scanf("%s",square[i]);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(square[i][j]=='.'){
                    check(square,i,j,n);
                    for(k=0;k<5;k++){
                        if(!flag[k]){
                            square[i][j]='A'+k;
                            break;
                        }
                    }
                }
            }
        }
        printf("Case %d:\n",t);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%c",square[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
