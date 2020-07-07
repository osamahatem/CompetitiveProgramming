#include<bits/stdc++.h>

using namespace std;

int ID,vis[256*256];
int di[]={1,1,-1,-1,2,2,-2,-2};
int dj[]={2,-2,2,-2,1,-1,1,-1};

int BFS(char si,char sj,char ti,char tj){
    if(si==ti && sj==tj)
        return 0;
    ID++;
    queue<int> Q;
    int steps=0;
    Q.push(si*256+sj);
    vis[si*256+sj]=ID;
    while(Q.size()){
        int s=Q.size();
        steps++;
        while(s--){
            si=Q.front()/256;
            sj=Q.front()%256;
            Q.pop();
            for(int k=0;k<8;k++){
                char ni=si+di[k];
                char nj=sj+dj[k];
                if(ni<'a' || ni>'h' || nj<'1' || nj>'8' || vis[ni*256+nj]==ID)
                    continue;
                if(ni==ti && nj==tj)
                    return steps;
                vis[ni*256+nj]=ID;
                Q.push(ni*256+nj);
            }
        }
    }
    return -1;
}

int main(){
    ID=0;
    char si,sj,ti,tj;
    while(scanf(" %c%c %c%c",&si,&sj,&ti,&tj)!=EOF){
        printf("To get from %c%c to %c%c takes %d knight moves.\n",si,sj,ti,tj,BFS(si,sj,ti,tj));
    }
    return 0;
}
