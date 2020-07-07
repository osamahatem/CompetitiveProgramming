#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    set<int> row,col;
    char g[105][105];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",g[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]=='.'){
                row.insert(i);
                col.insert(j);
            }
        }
    }
    if(row.size()<n && col.size()<n){
        printf("-1\n");
        return 0;
    }
    if(row.size()==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]=='.'){
                    printf("%d %d\n",i+1,j+1);
                    break;
                }
            }
        }
        return 0;
    }
    if(col.size()==n){
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(g[i][j]=='.'){
                    printf("%d %d\n",i+1,j+1);
                    break;
                }
            }
        }
        return 0;
    }
    return 0;
}
