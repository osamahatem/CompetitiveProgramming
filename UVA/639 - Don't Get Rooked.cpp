#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
char g[5][5];

void attack(int i,int j){
    int c=1;
    while(g[i][j+c]!='X' && j+c<n){
        g[i][j+c]++;
        c++;
    }
    c=1;
    while(g[i+c][j]!='X' && i+c<n){
        g[i+c][j]++;
        c++;
    }
    c=1;
    while(g[i-c][j]!='X' && i-c>=0){
        g[i-c][j]++;
        c++;
    }
    c=1;
    while(g[i][j-c]!='X' && j-c>=0){
        g[i][j-c]++;
        c++;
    }
    g[i][j]++;
    return;
}

void free(int i,int j){
    int c=1;
    while(g[i][j+c]!='X' && j+c<n){
        g[i][j+c]--;
        c++;
    }
    c=1;
    while(g[i+c][j]!='X' && i+c<n){
        g[i+c][j]--;
        c++;
    }
    c=1;
    while(g[i-c][j]!='X' && i-c>=0){
        g[i-c][j]--;
        c++;
    }
    c=1;
    while(g[i][j-c]!='X' && j-c>=0){
        g[i][j-c]--;
        c++;
    }
    g[i][j]--;
    return;
}

int maxrooks(){
    int maxi=0,i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(g[i][j]=='.'){
                attack(i,j);
                maxi=max(maxi,1+maxrooks());
                free(i,j);
            }
        }
    }
    return maxi;
}

int main(){
    while(1){
        scanf("%d ",&n);
        if(!n)
            break;
        for(int i=0;i<n;i++)
            gets(g[i]);
        printf("%d\n",maxrooks());
    }
    return 0;
}
