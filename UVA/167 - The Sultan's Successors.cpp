#include<cstdio>
#include<algorithm>

using namespace std;

int board[8][8];
int atk[8][8];

void attack(int i,int j){
    int c,x,y,a,b;
    for(c=0;c<8;c++){
        for(x=-1;x<=1;x++){
            for(y=-1;y<=1;y++){
                a=i+x*c;
                b=j+y*c;
                if(a>=0 && a<8 && b>=0 && b<8){
                    atk[a][b]++;
                }
            }
        }
    }
    return;
}

void free(int i,int j){
    int c,x,y,a,b;
    for(c=0;c<8;c++){
        for(x=-1;x<=1;x++){
            for(y=-1;y<=1;y++){
                a=i+x*c;
                b=j+y*c;
                if(a>=0 && a<8 && b>=0 && b<8){
                    atk[a][b]--;
                }
            }
        }
    }
    return;
}

int maxsum(int i){
    if(i==8){
        return 0;
    }
    int j,maxi=0;
    for(j=0;j<8;j++){
        if(atk[i][j]==0){
            attack(i,j);
            maxi=max(maxi,board[i][j]+maxsum(i+1));
            free(i,j);
        }
    }
    return maxi;
}

int main(){
    int k,i,j;
    scanf("%d",&k);
    while(k--){
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                scanf("%d",&board[i][j]);
                atk[i][j]=0;
            }
        }
        printf("%5d\n",maxsum(0));
    }
    return 0;
}
